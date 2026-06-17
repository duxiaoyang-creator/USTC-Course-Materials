/*
 * 002.c
 *
 * Created: 2025/5/7 19:07:00
 * Author : dxydu
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "twi_lcd.h"
unsigned char sf_data[8][8]={ //自定义字符:最多8个，可以是汉字
	{0x04,0x04,0x1F,0x0E,0x15,0x04,0x00,0x00}, //木
	{0x04,0x04,0x0E,0x04,0x04,0x1F,0x00,0x00}, //土
	{0x1E,0x12,0x12,0x1E,0x12,0x12,0x1E,0x00}, //日
	{0x08,0x1E,0x04,0x03,0x1F,0x0C,0x13,0x00}, //尧
	{0x18,0x14,0x18,0x14,0x18,0x10,0x00,0x00}, //包耳旁
	{0x1E,0x12,0x12,0x1E,0x12,0x12,0x1E,0x00}, //日
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}, //0
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} }; //0
	void LCD_CGR_Write() //将自定义的8个字符数据写入CGRAM
	{ unsigned char i,j;
		for(i=0;i<8;i++) for(j=0;j<8;j++)
		{ LCD_8Bit_Write(0x40+i*8+j,0); //确定地址
			LCD_8Bit_Write(sf_data[i][j],1); //将对应的自定义字符数据写入
		}
	}
int main(void) { int i;
	TWI_Init(); LCD_Init(); LCD_CGR_Write(); //初始化TWI和LCD，写入8个自定义
	LCD_Write_String(0,0,"LCD1602 Command 20250429");
	 _delay_ms(2000);
	LCD_8Bit_Write(0x01,0);/*清屏*/ 
	_delay_ms(2);
	LCD_Write_String(0,0,"PB23051023");
	LCD_8Bit_Write(0x18,0);_delay_ms(1); //左移一个字符
	LCD_8Bit_Write(0x18,0);_delay_ms(1);
	LCD_8Bit_Write(0x18,0);_delay_ms(1);
	LCD_8Bit_Write(0x18,0);_delay_ms(1);
	LCD_8Bit_Write(0x18,0);_delay_ms(1);
	_delay_ms(2000);
	for(i=0;i<8;i++)LCD_Write_Char(1,i,i); //显示自定义字符
	_delay_ms(2000);
	LCD_8Bit_Write(0x1C,0);_delay_ms(1); //右移一个字符
	LCD_8Bit_Write(0x1C,0);_delay_ms(1);
	LCD_8Bit_Write(0x1C,0);_delay_ms(1);
	LCD_8Bit_Write(0x1C,0);_delay_ms(1);
	LCD_8Bit_Write(0x1C,0);_delay_ms(1);
	while (1) { /*LCD_8Bit_Write(0x18,0);_delay_ms(500); */} }

