/*
 * 002.c
 *
 * Created: 2025/4/18 19:01:11
 * Author : dxydu
 */ 

#include <avr/io.h>
int main(void)
{
	DDRB |=(1<<DDRB1);//PB1(OC1A)为输出
	ICR1 =2048;//设置TOP值
	OCR1A = 1024;//设置A路比较值
	TCCR1A |= (1<<COM1A1);//设置输出比较管脚切换方式等
	TCCR1B |= (1<<WGM13)|(1<<CS12);//设置PWM模式为8，时钟256分频
	while (1)
	{
	}
}