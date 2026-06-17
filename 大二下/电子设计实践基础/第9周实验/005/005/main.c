/*
 * 005.c
 *
 * Created: 2025/4/25 19:55:17
 * Author : dxydu
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include "twi_lcd.h"
#include <util/delay.h>
int main(void)
{ unsigned char cmd_cnt=2,cmd_data[3]={0,0,0};//接收命令和数据
UCSRC = 0x80;//清空UCSRC
UBRRH = 0;//
UBRRL = 12;//1MHz,4800bps,0.2%
UCSRB = (1<<RXEN)|(1<<TXEN);//开启USART接收和发送
UCSRC =(1<<URSEL)|(3<<UCSZ0);//异步,无校验,8位数据，1位停止位,...
TWI_Init();
LCD_Init();
while (1)
{ if(UCSRA & (1<<RXC))//有收到数据
	{ cmd_data[cmd_cnt] = UDR;//读数据
	cmd_cnt--; }
	if(cmd_cnt<1)//收到两个字节
	{ switch(cmd_data[2])
		{//case 0xc0://LCD指令直接操作
			case 0x5c://proteus:\+命令
			LCD_8Bit_Write(cmd_data[1],0);
			break;
			case 0xc1://读忙标志
			break;
			//case 0xc2://往RAM写数据
			case 0x5d://proteus ]+显示字符
			LCD_8Bit_Write(cmd_data[1],1);
			break;
			case 0xc3://从RAM读数据
			break;
		}
		while(!(UCSRA & (1<<UDRE)));//等待发送
		UDR = 'O';//发送字符
		while(!(UCSRA & (1<<UDRE)));//等待发送
		UDR = 'K';//发送字符
		cmd_cnt=2;//接收下一次命令数据
	}
	_delay_ms(1);
} //while结束
} //main结束
		