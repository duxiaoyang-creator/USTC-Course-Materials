#include <avr/io.h>
#include "twi_lcd.h"

void ADC_Init(unsigned char adc_ch) //ADC初始化，低4bit,adc0~7:0~7
{
	ADMUX = (1 << REFS0) | (adc_ch & 0x0f); //参考电压：AVcc，低4bit选通道
	ADCSRA = (1 << ADEN) | (1 << ADFR) | (1 << ADPS1) | (1 << ADPS0); //开启ADC，连续模式,右对齐，预分频8，1000/8=125kHz
	ADCSRA |= (1 << ADSC); //ADC开始转换
}

float ADC_Read(unsigned char adc_ch)
{
	ADC_Init(adc_ch); //初始化指定通道的ADC
	while (!(ADCSRA & (1 << ADIF))); //等待ADC转换结束
	unsigned char adc_dl = ADCL; //先读低8位
	unsigned char adc_dh = ADCH; //再读高8位
	float adc_result = adc_dh * 256.0 + adc_dl; //合并
	adc_result *= 5.0 / 1024.0; //计算电压
	return adc_result;
}

int main(void)
{
	float adc_results[2]; // 存储两个通道的结果
	unsigned char uc_display[8];
	unsigned char i;

	TWI_Init();
	LCD_Init();
	ADC_Init(3);
	ADC_Init(2);

	while (1)
	{
		adc_results[0] = ADC_Read(3); // PC3
		adc_results[1] = ADC_Read(2); // PC2

		// 统一的电压显示函数
		void displayVoltage(unsigned char row, const char* label, float voltage) {
			LCD_Write_String(row, 0, label);
			
			// 清空显示缓冲区
			for(i = 0; i < 8; i++)
			uc_display[i] = ' ';
			
			// 整数部分
			unsigned int integer = (unsigned int)voltage;
			i = 2;
			while(integer > 0 && i > 0) {
				uc_display[i--] = '0' + integer % 10;
				integer /= 10;
			}
			if(i == 2) uc_display[i] = '0'; // 处理0值
			
			// 小数部分
			uc_display[3] = '.';
			unsigned int decimal = (unsigned int)((voltage - (int)voltage) * 100);
			uc_display[4] = '0' + decimal / 10;
			uc_display[5] = '0' + decimal % 10;
			
			LCD_Write_String(row, 8, uc_display);
		}

		displayVoltage(0, "PC3:", adc_results[0]);
		displayVoltage(1, "PC2:", adc_results[1]);
		
		_delay_us(300);
	}
}