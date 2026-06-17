/*
 * test.c
 *
 * Created: 2025/3/22 9:37:40
 * Author : dxydu
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{int i,j;
	DDRC = (1<<DDRC0); //PC0ÎªÊä³ö
	while (1)
	{
		for(i=0;i<100;i++)//½¥ÁÁ
		{ PORTC |= (1<<PORTC0);//PC[0]=1
			for(j=0;j<=i;j++)_delay_us(150);
			PORTC &= ~(1<<PORTC0);//PC[0]=0
			for(j=0;j<100-i;j++)_delay_us(150);
		}
		
		for(i=100;i>0;i--)//½¥°µ
		{ PORTC |= (1<<PORTC0);//PC[0]=1
			for(j=0;j<=i;j++)_delay_us(150);
			PORTC &= ~(1<<PORTC0);//PC[0]=0
			for(j=0;j<100-i;j++)_delay_us(150);
		}
	}
	
}
