/*
 * สตั้004.c
 *
 * Created: 2025/3/22 10:37:03
 * Author : dxydu
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char tpr1=0,tpr2=0,counter=0;
	DDRC =(1<<DDRC2)|(1<<DDRC1)|(1<<DDRC0);
	DDRB &=~(1<<DDRB1);
	while(1){
		tpr2=tpr1;
		tpr1=(PINB&(1<<PINB1))>>1;
		if(tpr2==0&&tpr1==1)counter++;
		switch (counter) {
			case 1:
			PORTC=(1<<PORTC2);
			break;
			case 2:
			PORTC=(1<<PORTC1);
			break;
			case 3:
			PORTC=(1<<PORTC0);
			break;
			default:
			PORTC=0;counter=0;
			break;
		}
	}
    /* Replace with your application code */
}

