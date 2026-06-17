#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1/8000000UL


int main() {
	
	while(1) {
		DDRC|=(1<<DDRC2)|(1<<DDRC1)|(1<<DDRC0);
		while (1)
		{ PORTC =(1<<PORTC2);
			_delay_ms(1000);
			PORTC = (1<<PORTC1);
			_delay_ms(1000);
			PORTC = (1<<PORTC0);
			_delay_ms(1000);
		}
	}
}