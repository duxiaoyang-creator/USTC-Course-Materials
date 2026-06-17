/*
 * TWI_MT.c

 * Created: 2025/4/2 10:38:32
 * Author : 33912
 */ 
#define F_CPU 10000000UL
#include <avr/io.h>
#include "twi_fun.h"
#include <util/delay.h>
#include <avr/interrupt.h>
unsigned char counter=0;
#include <avr/io.h>
#include <util/twi.h> // TWI接口状态码定义
#include "twi_lcd.h"
ISR(INT0_vect)
{
    if(counter <9999)
    counter++;
    else
    counter = 0;
}
int main(void)
{
    _delay_ms(100);  // 100ms 延时
    unsigned char sla_w = 0x33<<1;//从MCU地址为0x33(位0为开启广播)，写从MCU
    DDRC &= ~((1<<DDRC5)|(1<<DDRC4));//PC5/4为输入
    PORTC |= (1<<PORTC5)|(1<<PORTC4);//开启内部上拉
    TWI_Init();
    DDRD &=~(1<<DDRD2);            //PD2(int0) 接触摸开关的sig管脚
    MCUCR|=((1<<ISC01)|(1<<ISC00));//int0管脚是上升沿触发中断INT0
    GICR |= (1<<INT0);            //允许INT0外部中断
    sei();                        //开启全局中断SREG(I)=1
    while (1) 
    {
        TWI_Start();
        if((TWSR & 0xf8) == TW_START)//START已发出
        {
            TWDR=sla_w;//发送SLA+W
            TWCR=(1<<TWINT)|(1<<TWEN);//清除标志，并发送sla+w
            while(!(TWCR & (1<<TWINT)));//等待sla+w发出
            if((TWSR & 0xf8)==TW_MT_SLA_ACK)//sla+W已发出
            {
                TWI_Write(counter);
                if((TWSR & 0xf8)==TW_MT_DATA_ACK)   //数据已发出
                TWI_Stop();//清标志，发STOP
            }
        }
        TWCR=(1<<TWINT);//清除标志位，禁止TWI
        _delay_ms(50);
    }
}