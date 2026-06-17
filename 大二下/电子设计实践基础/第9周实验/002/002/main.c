/*
 * 002.c
 *
 * Created: 2025/4/25 18:59:10
 * Author : dxydu
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include "twi_lcd.h"
#include <util/delay.h>
int main(void)
{ unsigned char i=2,ch=33; //变量
	//UCSRC = 0x80; //清空UCSRC
	UBRRH = 0;
	UBRRL = 12; //1MHz,4800bps,0.2%
	UCSRB = (1<<RXEN)|(1<<TXEN);
	//开启USART接收和发送
	UCSRC =(1<<URSEL)|(3<<UCSZ0);
	//异步,无校验,8位，1停止位,...
	TWI_Init();
	LCD_Init();
	LCD_Write_String(0,0,"S:");
	//LCD第1行提示
	LCD_Write_String(1,0,"R:");
	//LCD第2行提示
	while (1)
	{ LCD_Write_Char(0,i,ch); //显示发送的数据
		while(!(UCSRA & (1<<UDRE)));//等待发送
		//可以发送数据？
		UDR = ch; //发送数据
		//_delay_us(100);
		_delay_ms(200); //等待发送
		while(!(UCSRA & (1<<RXC))); //等待接收
		LCD_Write_Char(1,i,UDR); //显示接收数据
		if(i==15) i=2; //绕回来显示
		else i++;
		if(ch==127) ch=161; //跳过
		else if(ch==223) ch=33; //绕回来
		else ch++; //下一个可以显示的字符
		_delay_ms(200);
	} //while结束
} //main结束