/*
 * m_28byj48.h
 *
 * Created: 2025/4/18 19:37:15
 *  Author: dxydu
 */ 

#ifndef M_28BYJ48_H_
#define M_28BYJ48_H_ //头文件 "m_28byj48.h"
#ifndef F_CPU
#define F_CPU 1000000UL /*<util/delay.h>需要定义F_CPU参数*/
#endif
#include <util/delay.h> //包含延时函数_delay_ms()和_delay_us()等
#include <avr/io.h>
/* 3种不同驱动方式下28byj48步进电机的控制信号，脉冲数据
* 低4位中bit3控制28byj48的蓝色线(D),bit2-粉(C),bit1-黄(B),bit0-橙(A)*/
const unsigned char
stepper_ph[3][8]={{0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09},//混合8拍
{0x03,0x06,0x0C,0x09}, //双4拍
{0x01,0x02,0x04,0x08}}; //单4拍
unsigned char stepper_index = 0; //记录并控制步进电机的步伐
/* 28BYJ-48步进电机的控制函数，其参数的作用为：
* phase:选择步进电机的驱动方式，0：8拍，1：双4拍，2：单4拍
* dir:步进电机的转动方向，0：顺时针，1：逆时针
* step:控制步进电机转动多少步（多少个脉冲），0~65535*/
void run_stepper(unsigned char phase,unsigned char dir,unsigned int step)
{ unsigned char ph = phase ? 0x03:0x07; //驱动方式，确定脉冲的选择增量
	unsigned char inc = dir ?0x01:ph; /*逆时针增量为1，顺时针 4拍为3,8拍为7*/
	unsigned int i; //定义循环变量i
	DDRC |=(1<<DDRC3)|(1<<DDRC2)|(1<<DDRC1)|(1<<DDRC0);//PC输出
	for(i=0;i<step;i++) //输出step个脉冲步
	{ stepper_index += inc; //通过增量调整，不断地切换输出脉冲
		stepper_index &= ph; //去掉递增后的无效高位值
		PORTC &=0xf0; //选择相应的控制脉冲通过端口C进行输出
		PORTC |= stepper_ph[phase][stepper_index];
		_delay_us(900);//8拍 _delay_us(1600);//双4拍//_delay_us(2000);//单四拍
	} }
#endif /* M_28BYJ48_H_ */