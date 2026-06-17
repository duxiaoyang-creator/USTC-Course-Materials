#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned int counter=0;


int main(void)
{
	unsigned char seg7_hex[16]=
	{0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,
	0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e};
	unsigned char i,seg7_com[4]={0xe,0xd,0x0b,0x07};
	unsigned int d_t;
	DDRC = (0x0f);
	DDRB = (0xff);
	DDRD &= ~(1<<DDRD3);
	MCUCR |=((1<<ISC11)|(1<<ISC10));
	GICR |= (1<<INT1);
	sei();
	while (1)
	{
		d_t = counter;
		for(i=0;i<4;i++)
		{ PORTC |=0x0f; //禁止显示
			PORTB =seg7_hex[d_t%10];//送数
			PORTC =seg7_com[i]; //显示
			d_t=d_t/10; //下一位
			_delay_ms(5);
		}
	}
}
ISR(INT1_vect)
{if(counter < 9999) counter++;
else counter = 0; }
