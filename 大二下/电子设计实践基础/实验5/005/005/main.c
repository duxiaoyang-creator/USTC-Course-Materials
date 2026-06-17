/*
 * 005.c
 *
 * Created: 2025/4/18 19:36:05
 * Author : dxydu
 */ 

#include <avr/io.h>
#include "m_28byj48.h"
int main(void)
{ DDRD &=~(1<<DDRD0); //输入：通过PD0控制电机正反转
	PORTD |=(1<<PORTD0); //内部上拉
	while (1)
	{ if(PIND & (1<<PIND0))
		run_stepper(0,1,4096);
		//8拍驱动方式，顺时针，转动一周
		else
		run_stepper(0,0,4096);
		//8拍驱动方式，逆时针，转动一周
	}
}