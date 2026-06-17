/*
 * 002.c
 *
 * Created: 2025/4/11 18:48:24
 * Author : dxydu
 */ 

#include <avr/io.h>
#include "twi_lcd.h"
#include "hc_sr04.h"
int main(void) //根据需要补充完整


{
	unsigned int distance=0;
	unsigned char i=15,uc_d=0;
	TWI_Init(); LCD_Init();
	while (1)
	{ distance = HCSR04_Run();
		LCD_Write_String(0,0,"Distance:");
		i=15; //从最低位开始转换和显示，最多7位
		while(distance>0)
		{ uc_d = distance % 10+0x30;
			LCD_Write_Char(0,i,uc_d);
		i--; distance /=10;}
		while(i>8) //高位没有数字时不显示
		{ LCD_Write_Char(0,i,0x20);
		i--; }
		_delay_ms(100);//
	}
}