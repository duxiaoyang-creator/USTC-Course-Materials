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
	DDRC |= (1<<DDRC2)|(1<<DDRC1)|(1<<DDRC0);
	while (1)
	{ PORTC = ~(1<<PORTC2);//only red on
		for(i=0;i<100;i++) for(j=0;j<1000;j++);
		PORTC = ~(1<<PORTC1);//only green on
		for(i=0;i<100;i++) for(j=0;j<1000;j++);
		PORTC = ~(1<<PORTC0);//only blue on
		for(i=0;i<100;i++) for(j=0;j<1000;j++);
		// 5. Æ·ºì (ºì+À¶)£¬PB3 ºÍ PB1 ÁÁ£¬PB2 Ãð
		PORTC = (1<<PORTC3)|(1<<PORTC1);
		_delay_ms(500);  // ÑÓÊ±500ms
		// 6. ÇàÉ« (ÂÌ+À¶)£¬PB2 ºÍ PB1 ÁÁ£¬PB3 Ãð
		PORTC = (1<<PORTC2)|(1<<PORTC1);
		_delay_ms(500);  // ÑÓÊ±500ms
		// 7. °×É« (ºì+ÂÌ+À¶)£¬PB3¡¢PB2 ºÍ PB1 ¶¼ÁÁ
		PORTC = (1 <<PORTC3)|(1<<PORTC2)|(1<<PORTC1);
		_delay_ms(500);  // ÑÓÊ±500ms
	}
}