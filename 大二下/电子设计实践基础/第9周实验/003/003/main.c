/*
 * 003.c
 *
 * Created: 2025/4/25 19:04:00
 * Author : dxydu
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include "twi_lcd.h"
#include <util/delay.h>
int main(void)
{ unsigned char i=0,tp_r=0; //临时变量
	TCNT0 = 0; //利用TC0统计开关的次数
	TCCR0 = (1<<CS02)|(1<<CS01)|(1<<CS00);
	//对T0上升沿计数
	UCSRC = 0x80; //清空UCSRC
	UBRRH = 0; //
	UBRRL = 12; //1MHz,4800bps,0.2%
	UCSRB = (1<<RXEN)|(1<<TXEN);
	//开启USART接收和发送
	UCSRC =(1<<URSEL)|(3<<UCSZ0);
	//异步,无校验,8位数据，1位停止位,...
	TWI_Init();
	LCD_Init();
	LCD_Write_String(0,0,"a:Touchpad");
	while (1)
	{ if(tp_r!=TCNT0) //开关次数发生变化
		{ tp_r = TCNT0;
			//读取TCNT0，即新的开关次数
			while(!(UCSRA & (1<<UDRE)));
			//可以发送数据？
			UDR = tp_r; //发送数据
		}
		if(UCSRA & (1<<RXC)) //有收到数据?
		{ LCD_Write_Char(1,i,UDR); //显示
			i++;
		}
		if(i>15)i=0; //逐次显示，并回退
		_delay_ms(1);
	}
}