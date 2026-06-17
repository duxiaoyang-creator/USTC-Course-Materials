/*
 * 003.c
 *
 * Created: 2025/5/7 19:25:16
 * Author : dxydu
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned char duty=50; //占空比，百分比
unsigned int freq=30; //频率：30~3000Hz范围可调( 实测29.8~2.7K)
ISR(INT0_vect)
{ if(duty > 90)//百分比
	duty = 10;
else duty +=10; }
ISR(INT1_vect)
{ if(freq >2000) freq = 30;
else freq +=100; }
int main(void) {
	DDRD &=~((1<<DDRD2) |(1<<DDRD3)); //分别调整占空比和频率
	PORTD |=(1<<PORTD2)|(1<<PORTD3); //开启内部上拉电阻，默认高电平
	DDRB |=(1<<DDRB1); //PB1控制蜂鸣器的IO
	MCUCR |=(1<<ISC01)|(1<<ISC11); //INT0和INT1下降沿触发
	GICR |=(1<<INT0)|(1<<INT1); //开中断
	sei(); //全局中断开
	unsigned int high,low,i;
	while (1) {
		high = F_CPU/14/freq/100*duty; //换算为高电平的周期数
		low = F_CPU/14/freq - high - 160; //换算为低电平的周期数
		PORTB |=(1<<PORTB1);for(i=0;i<high;i++) _delay_us(1); //高电平持续
		PORTB &=~(1<<PORTB1);for(i=0;i<low;i++) _delay_us(1); //低电平持续
	}
}