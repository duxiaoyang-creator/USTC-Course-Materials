/*
 * Test_2 SR.c
 *
 * Created: 2025/4/2 11:36:34
 * Author : 33912
 */ 
#define F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "twi_fun.h"
#include "twi_lcd.h"
unsigned char counter = 0;  // 显式初始化

int main(void)
{
    unsigned int d_t,i = 0;
    char chs[4];
    unsigned char counter=0;
    unsigned char sla_addr = 0x33<<1;//从机地址为0x33(最低位为开启广播)
    TWCR=0x0;                //禁止TWI接口
    DDRC &=~((1<<DDRC5)|(1<<DDRC4));//PC5/4输入
    PORTC |=(1<<PORTC5)|(1<<PORTC4);  //SCL/SDA内部上拉
    TWAR=sla_addr;            //设置从机地址
    LCD_Init();
    while (1)
    {
        //TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);//清标志，开TWI，自动应答
        //while(!(TWCR & (1<<TWINT)));//等待接收sla+w
        TWI_Read_With_ACK();
        if((TWSR & 0xf8)==TW_SR_SLA_ACK)//sla+W已收到，已发ACK
        {
            //TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);//清除标志，开启ACK
            //while(!(TWCR & (1<<TWINT)));//等待接收数据
            TWI_Read_With_ACK();
            if((TWSR & 0xf8)==TW_SR_DATA_ACK)      //数据已收到，已发ACK
            {
                counter = TWDR;//收到的数据存储在counter里
                TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);//
            }
        }
        TWCR=(1<<TWINT);//清除TWINT标志，关闭TWI接口
        d_t = counter;
        for(i=0;i<4;i++)//1个整数转换为4位字符
        {
            chs[3-i]=d_t%10+0x30;
            d_t=d_t/10;
        }
        //chs[4] = '\0';  // 终止字符串
        LCD_Write_String(0,1,"Touchpad Times:");
        LCD_Write_String(1,3,chs);
        _delay_ms(50);
    }
}