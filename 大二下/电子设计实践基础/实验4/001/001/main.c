/*
 * 001.c
 *
 * Created: 2025/4/8 21:24:33
 * Author : dxydu
 */ 
#include <avr/io.h>
#include "twi_lcd.h"
#include "dht11.h"
int main(void)
{
	unsigned char toggle=1,dht11_data[5]={0};
	TWI_Init();
	LCD_Init();
	while (1)
	{ DHT11_Run(dht11_data);
		if(dht11_data[4]==(dht11_data[0]+dht11_data[1]+dht11_data[2]+dht11_data[3]))
		{ LCD_Write_String(0,0,"Temperature:"); //显示温度
			LCD_Write_NewChar(dht11_data[2]/10%10+0x30);
			LCD_Write_NewChar(dht11_data[2]%10+0x30);
			LCD_Write_String(1,0,"Humidity:"); //显示湿度
			LCD_Write_NewChar(dht11_data[0]/10%10+0x30);
			LCD_Write_NewChar(dht11_data[0]%10+0x30);
		}
		if(toggle) //数据更新提示（一个符号闪烁）
		{ LCD_Write_Char(1,15,0x5c); //显示符号
		toggle = 0;}
		else
		{ LCD_Write_Char(1,15,0x20); //不显示符号
		toggle = 1; }
		_delay_ms(1500);
	} //while
} //main