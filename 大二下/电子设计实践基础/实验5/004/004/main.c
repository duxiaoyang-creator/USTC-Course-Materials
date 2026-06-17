
/*
 * 004.c
 *
 * Created: 2025/4/18 19:08:19
 * Author : dxydu
 */ 
#include <avr/io.h>
#include "twi_lcd.h"
#include <avr/interrupt.h>
unsigned char counter=1;

ISR(INT0_vect)
{if(counter <20)
	counter++;
	else
	counter = 1;
}
ISR(TIMER1_OVF_vect)
{
	OCR1A = counter * 6;
}

int main(void)
{ unsigned char uc_tmp; TWI_Init(); LCD_Init();
	DDRB |=(1<<DDRB1); //PB1(OC1A)输出
	ICR1 = 200;/*TOP值*/ OCR1A = 10; //A路比较值
	TCCR1A |= (1<<COM1A1)|(1<<COM1A0);//管脚切换方式
	TCCR1B |= (1<<WGM13)|(1<<CS11);//模式为8，时钟8分频
	TIMSK =(1<<TOIE1); //开启TC1溢出中断
	DDRD &= ~(1<<DDRD2); //PD2(int0)为输入<-tp223
	MCUCR |=((1<<ISC01)|(1<<ISC00)); //int0 上升沿触发中断
	GICR |= (1<<INT0);/*允许INT0中断*/ sei(); //开全局中断
	while (1) { uc_tmp = counter;
		LCD_Write_Char(0,6,uc_tmp/10+0x30);
		LCD_Write_NewChar(uc_tmp%10+0x30);
	_delay_ms(2); }
}