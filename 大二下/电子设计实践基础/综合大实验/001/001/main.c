#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "twi_lcd.h"

#define F_CPU 1000000UL

// 红外解码变量（根据图片中的键值表）
volatile uint32_t ir_code = 0;
volatile uint8_t ir_ready = 0;
const uint16_t USER_CODE = 0x00FF; // 用户码匹配值

// 按键码定义（完全匹配图片中的键值）
typedef enum {
	KEY_CH_MINUS  = 0x45, // CH-
	KEY_CH        = 0x46, // CH
	KEY_CH_PLUS   = 0x47, // CH+
	KEY_PREV      = 0x44, // PREV
	KEY_NEXT      = 0x40, // NEXT
	KEY_PLAY_PAUSE= 0x43, // PLAY/PAUSE
	KEY_VOL_MINUS = 0x07, // VOL-
	KEY_VOL_PLUS  = 0x15, // VOL+
	KEY_EQ        = 0x09, // EQ
	KEY_0         = 0x16, // 0
	KEY_100_PLUS  = 0x19, // 100+
	KEY_200_PLUS  = 0x0D  // 200+
} RemoteKeys;

// 红外初始化（严格匹配38kHz载波）
void ir_init() {
	DDRD &= ~(1 << PD2);    // INT0输入（接红外OUT）
	PORTD |= (1 << PD2);    // 上拉电阻
	
	// 中断配置（下降沿触发）
	MCUCR |= (1 << ISC01);
	GICR |= (1 << INT0);
	
	// Timer1用于精确测量脉冲宽度（1MHz/8=0.5μs分辨率）
	TCCR1B = (1 << CS11);
	sei();
}

// 中断服务程序（NEC协议解码优化版）
ISR(INT0_vect) {
	static uint32_t start_time = 0;
	static uint8_t bit_cnt = 0;
	
	uint16_t pulse_width = TCNT1 - start_time;
	start_time = TCNT1;

	// 引导码检测（9ms±10%）
	if(pulse_width > 16000 && pulse_width < 20000) {
		ir_code = 0;
		bit_cnt = 0;
		return;
	}
	
	// 数据位处理（32位：16用户码+8键码+8键码反码）
	if(bit_cnt < 32) {
		// 逻辑1检测（1.68ms±15%）
		if(pulse_width > 1428 && pulse_width < 1932) {
			ir_code |= (1UL << (31 - bit_cnt));
		}
		bit_cnt++;
		
		// 完整接收后验证用户码和反码
		if(bit_cnt == 32) {
			uint16_t received_user = ir_code >> 16;
			uint8_t key_code = ir_code >> 24;
			uint8_t key_inv = ~(ir_code >> 16) & 0xFF;
			
			if(received_user == USER_CODE &&
			((ir_code >> 8) & 0xFF) == (uint8_t)(~key_code)) {
				ir_ready = 1;
			}
		}
	}
}

// LCD显示函数（带防闪烁）
void display_remote(uint8_t key) {
	static uint8_t last_key = 0xFF;
	if(key == last_key) return;
	
void LCD_Init(); //初始化LCD1602;

	
	// 第一行显示用户码和键值
	LCD_Write_String(0, 0, "User:00FF Key:");
	LCD_Write_Char(0, 14, "0123456789ABCDEF"[key >> 4]);
	LCD_Write_Char(0, 15, "0123456789ABCDEF"[key & 0x0F]);
	
	// 第二行显示功能描述（完全匹配图片）
	LCD_Write_String(1, 0, "Func:");
	switch(key) {
		case KEY_CH_MINUS:  LCD_Write_String(1, 5, "CH-      "); break;
		case KEY_CH:        LCD_Write_String(1, 5, "CH       "); break;
		case KEY_CH_PLUS:   LCD_Write_String(1, 5, "CH+      "); break;
		case KEY_PREV:      LCD_Write_String(1, 5, "PREV     "); break;
		case KEY_NEXT:      LCD_Write_String(1, 5, "NEXT     "); break;
		case KEY_PLAY_PAUSE:LCD_Write_String(1, 5, "PLAY/PAUSE"); break;
		case KEY_VOL_MINUS: LCD_Write_String(1, 5, "VOL-     "); break;
		case KEY_VOL_PLUS:  LCD_Write_String(1, 5, "VOL+     "); break;
		case KEY_EQ:        LCD_Write_String(1, 5, "EQ       "); break;
		case KEY_0:         LCD_Write_String(1, 5, "0        "); break;
		case KEY_100_PLUS:  LCD_Write_String(1, 5, "100+     "); break;
		case KEY_200_PLUS:  LCD_Write_String(1, 5, "200+     "); break;
		default:            LCD_Write_String(1, 5, "UNKNOWN  "); break;
	}
	last_key = key;
}

int main() {
	// 硬件初始化
	TWI_Init();
	LCD_Init();
	ir_init();
	
	// 显示启动信息
	LCD_Write_String(0, 0, "Car Media Remote");
	LCD_Write_String(1, 0, "Waiting signal...");
	_delay_ms(1000);

	while(1) {
		if(ir_ready) {
			uint8_t key_code = (ir_code >> 24) & 0xFF;
			display_remote(key_code);
			ir_ready = 0;
		}
		_delay_ms(50); // 降低CPU占用
	}
}