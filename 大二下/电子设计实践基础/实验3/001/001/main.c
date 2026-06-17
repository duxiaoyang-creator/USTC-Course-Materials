/*
 * 001.c
 *
 * Created: 2025/4/2 16:30:34
 * Author : dxydu
 */ 

#include <avr/io.h>
#include "twi_lcd.h"
int main(void)
{
	TWI_Init();
	LCD_Init();
	while (1)
	{
		LCD_Write_String(0,3,"Duxiaoyang");
		LCD_Write_String(1,3,"PB23051023.");
	}
}