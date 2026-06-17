/*
 * 003.c
 *
 * Created: 2025/4/18 19:04:17
 * Author : dxydu
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRB |=(1<<DDRB1)|(1<<DDRB2); //PB1(OC1A),PB2(OC1B)为输出
	ICR1 = 500; //设置TOP值
	OCR1A = 1; //设置A路比较值
	OCR1B = 1; //设置B路比较值
	TCCR1A |= (1<<COM1A1)|(1<<COM1A0)|(1<<COM1B1)|(1<<COM1B0);
	//设置’输出比较’管脚切换方式等
	TIMSK = (1<<TOIE1); //开启TC1溢出中断
	sei(); //开启全局中断
	TCCR1B |= (1<<WGM13)|(1<<CS11); //设置PWM模式为8，时钟8分频
	while (1)
	{ }
}unsigned char ui_cnt=0; //统计中断次数，确定OCR1A/B的值
ISR(TIMER1_OVF_vect)
{ ui_cnt++; //统计TC1溢出中断次数
	if(ui_cnt>249)ui_cnt=0; //统计到250次时清零
	if(ui_cnt<125) //前半程
	{ OCR1A = 0; //高电平的持续时间长
		OCR1B +=4; //高电平的持续时间渐短
	}
	else //后半程
	{ OCR1A =500;//低电平的持续时间长
		OCR1B -=4; //高电平的持续时间渐长
	}
}