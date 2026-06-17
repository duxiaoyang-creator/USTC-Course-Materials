#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "twi_lcd.h"
#include "dht11.h"
#include "hc_sr04.h"
#define F_CPU 1000000UL

unsigned char counter = 1;  // 系统状态变量
 int man = 0;

// 系统模式和PWM占空比
volatile uint8_t system_mode = 0; // 0=自动模式, 1=手动模式
volatile uint8_t pwm_duty = 0;    // 手动模式PWM占空比

// PWM初始化（Timer1 Fast PWM）
void pwm_init() {
	DDRB |= (1 << DDRB1);      // PB1 (OC1A) 输出
	ICR1 = 200;                // 设置TOP值
	OCR1A = 10;                // 设置A路比较值，控制占空比
	TCCR1A |= (1 << COM1A1) | (1 << COM1A0);  // 配置OC1A输出模式
	TCCR1B |= (1 << WGM13) | (1 << CS11);    // 设置Fast PWM模式和时钟分频8
	TIMSK |= (1 << TOIE1);      // 启用定时器1溢出中断
	DDRD &= ~(1 << DDRD2);     // 设置PD2 (INT0) 为输入
	// 中断配置
	MCUCR |= ((1 << ISC01) | (1 << ISC00));  // 配置INT0上升沿触发
	GICR |= (1 << INT0);       // 启用INT0中断
	sei();                     // 启用全局中断
}

ISR(INT0_vect) { // 触摸开关中断
	system_mode ^= 1;
	if (counter < 30)
	counter++;
	else
	counter = 1;
	if (man < 3)
	man++;
	else
	man = 0;
	_delay_ms(50); // 消抖
}

ISR(TIMER1_OVF_vect) {
	OCR1A = counter * 6;
}

int main() {
	// 初始化模块
	DDRC |= 0x07; // RGB LED
	pwm_init();
	TWI_Init();
	LCD_Init();
	unsigned char dht11_data[5]={0};
	unsigned char uc_tmp;
	unsigned int distance=0;
	DDRB |= (1 << DDRB1);      // PB1 (OC1A) 输出
	ICR1 = 200;                // 设置TOP值
	OCR1A = 15;                // 设置A路比较值，控制占空比
	TCCR1A |= (1 << COM1A1) | (1 << COM1A0);  // 配置OC1A输出模式
	TCCR1B |= (1 << WGM13) | (1 << CS11);    // 设置Fast PWM模式和时钟分频8
	TIMSK |= (1 << TOIE1);      // 启用定时器1溢出中断
	DDRD &= ~(1 << DDRD2);     // 设置PD2 (INT0) 为输入
	// 中断配置
	MCUCR |= ((1 << ISC01) | (1 << ISC00));  // 配置INT0上升沿触发
	GICR |= (1 << INT0);       // 启用INT0中断
	sei();                     // 启用全局中断

	while (1) {
		// 读取环境数据
		
		DHT11_Run(dht11_data);
		distance = HCSR04_Run();
		
		unsigned char i=15,uc_d=0;
		if(man==0)
		{
			system_mode=0;
			// 自动模式控制
			if(dht11_data[4]==(dht11_data[0]+dht11_data[1]+dht11_data[2]+dht11_data[3]))
			{

					// 根据温度控制PWM占空比，温度越高，电机转速越高
					// 线性映射：10~40°C => 0~180
					if (dht11_data[2] > 39)
					{
						counter = 1;
					} else if (dht11_data[2] < 10)
					{
						counter = 30;
					} else
					{
						counter = ( 40-dht11_data[2]);
					}
					OCR1A = counter * 6;  // 更新PWM占空比
					// 距离警示（<100cm亮红灯）
					PORTC = (distance < 100) ? 0x01 : 0x02;
				
			}
		}
		
		if (man != 0) {
			
				if (man == 1)
				counter = 30;
				else if (man == 2)
				counter = 20;
				else
				if (man == 3)
				counter = 10;
			
			OCR1A = counter * 6;  // 更新PWM占空比
		}
	
		PORTC = (distance < 100) ? 0x01 : 0x02;
		if(dht11_data[4]==(dht11_data[0]+dht11_data[1]+dht11_data[2]+dht11_data[3]))
		{    LCD_Write_String(0, 0, "T:");
			LCD_Write_NewChar(dht11_data[2]/10%10+0x30);
			LCD_Write_NewChar(dht11_data[2]%10+0x30);
			
			LCD_Write_String(0, 6, "H:");
			LCD_Write_NewChar(dht11_data[0]/10%10+0x30);
			LCD_Write_NewChar(dht11_data[0]%10+0x30);
			
		}

		// 显示PWM占空比
		uc_tmp = counter;
		
		LCD_Write_String(0, 12, "S:");
		if(man==0)
		{
			
			LCD_Write_Char(0, 14, uc_tmp / 10 + 0x30);
			LCD_Write_NewChar(uc_tmp % 10 + 0x30);
			
			_delay_ms(2);
		}
		if (man==1)
		{
			uc_tmp=30;
			LCD_Write_Char(0, 14, uc_tmp / 10 + 0x30);
			LCD_Write_NewChar(uc_tmp % 10 + 0x30);
		}
		if (man==2)
		{
			uc_tmp=20;
			LCD_Write_Char(0, 14, uc_tmp / 10 + 0x30);
			LCD_Write_NewChar(uc_tmp % 10 + 0x30);
		}
		if (man==3)
		{
			uc_tmp=10;
			LCD_Write_Char(0, 14, uc_tmp / 10 + 0x30);
			LCD_Write_NewChar(uc_tmp % 10 + 0x30);
		}
		PORTC = (distance < 100) ? 0x01 : 0x02;
		// 显示模式
		LCD_Write_String(1, 0, (man == 0) ? "Auto" : "Manual");
		LCD_Write_String(1, 8, "D:");
		
		// 显示距离
		i=15;
		while (distance > 0) {
			unsigned char uc_d = distance % 10 + 0x30;
			LCD_Write_Char(1, i, uc_d);
			i--;
			distance /= 10;
		}
		while (i > 9) { // 高位没有数字时不显示
			LCD_Write_Char(1, i, ' ');
			i--;
		}
		_delay_ms(1000);
	}
}
