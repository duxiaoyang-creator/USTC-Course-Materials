#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned int t_icr1 = 0;  // 记录TOP值
// 定义音符频率（单位Hz，C调标准音高）
#define NOTE_C4  262  // 低音Do
#define NOTE_D4  294  // Re
#define NOTE_E4  330  // Mi
#define NOTE_F4  349  // Fa
#define NOTE_G4  392  // So
#define NOTE_A4  440  // La
#define NOTE_B4  494  // Si
#define NOTE_C5  523  // 中音Do
#define NOTE_G3  196  // 网页4中低音SO对应392Hz，此处G3需降八度
// 两只老虎主旋律（C调简谱对应频率）
const uint16_t melody[] = {
	NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4,        // 两只老虎，两只老虎
	NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4,        // 跑得快，跑得快
	NOTE_E4, NOTE_F4, NOTE_G4,                 // 一只没有耳朵
	NOTE_E4, NOTE_F4, NOTE_G4,                 // 一只没有尾巴
	NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4,  // 真奇怪！真奇怪！
	NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_C4,  // (重复段)
	NOTE_C4, NOTE_G3, NOTE_C4                   // 结尾音
};

// 每个音符的持续时间（单位ms）
const uint16_t duration[] = {
	500,500,500,500,    // 四分音符 x4
	500,500,500,500,    // 四分音符 x4
	750,250,1000,       // 附点四分+八分+二分
	750,250,1000,       // 同上
	250,250,250,250,500,500,  // 八分音符群+四分
	250,250,250,250,500,500,  // 同上
	1000,500,1500 ,    // 二分+四分+附点二分
	1000,500,1500       // 二分+四分+附点二分
};
// 中断服务程序：INT1触发时改变PWM频率
ISR(INT1_vect) {
	if (ICR1 < 200) {
		// 如果TOP值小于200，则设置为25000（频率最低值）
		ICR1 = 25000;
		} else {
		// 否则，减小TOP值，增加频率
		ICR1 -= t_icr1 / 20;
	}
	t_icr1 = ICR1;
	OCR1A = ICR1 / 2;  // 50%的占空比
}
void play_note(uint16_t frequency, uint16_t duration_ms) {
	ICR1 = F_CPU / 8 / frequency;    // 设置频率
	OCR1A = ICR1 / 2;                // 设置占空比50%
	// 简化的延时
	while (duration_ms--) {
		_delay_ms(1);                // 每次延迟3ms
	}
	OCR1A = 0;                       // 停止播放音符
}

int main(void) {
	DDRB |= (1 << DDB1);  // 设置PB1(OC1A)为输出
	t_icr1 = ICR1 = 25000;  // 设置TOP值为25000
	OCR1A = ICR1 / 2;  // 设置占空比为50%

	// 配置定时器1
	TCCR1A |= (1 << COM1A1) | (1 << COM1A0);  // 设置PWM输出模式
	TCCR1B |= (1 << WGM13) | (1 << CS11);     // 设置时钟8分频，模式8

	// 配置INT1外部中断
	DDRD &= ~(1 << DDD3);  // 设置PD3为输入（外部中断1）
	MCUCR |= (1 << ISC11) | (1 << ISC10);  // INT1触发方式：上升沿
	GICR |= (1 << INT1);  // 使能INT1中断

	sei();  // 开启全局中断

	// 播放歌曲《一闪一闪亮晶晶》
	for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
		play_note(melody[i], duration[i]);  // 播放每个音符
	}

	// 播放完成后，进入死循环
	while (1) {
		// 可以在这里添加其他功能或操作
	}
}
