/*
 * 001.c
 *
 * Created: 2025/4/18 18:43:42
 * Author : dxydu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

// 添加中断服务程序声明
ISR(TIMER0_OVF_vect)
{
	PORTC ^= (1 << PORTC0); // LED状态切换
}

int main(void)
{
	DDRC |= (1 << DDC0);    // 正确设置PC0为输出(使用DDC0而不是DDRC0)
	PORTC &= ~(1 << PORTC0); // 初始化为低电平
	
	TCNT0 = 0;              // 计数器从0开始
	TIMSK |= (1 << TOIE0);  // 允许定时器溢出中断
	
	// 配置定时器: 1024分频, 普通模式
	TCCR0 = (1 << CS02) | (1 << CS00);
	
	sei();                  // 开启全局中断

	while (1)
	{
		// 主循环保持空转
	}
}