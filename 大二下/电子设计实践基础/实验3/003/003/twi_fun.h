/*
 * twi_fun.h
 *
 * Created: 2025/4/2 16:36:56
 *  Author: dxydu
 */ 


#ifndef TWI_FUN_H_
#define TWI_FUN_H_
#include <util/twi.h> //软件自带TWI接口的寄存器等头文件
void TWI_Init(void)//twi接口的初始化
{   //设置SCL的频率：1MHz cpu-50KHz scl,2M-100K,8M-400K
	
	TWSR = 0x00; //最低2位为预分频设置(00-1,01-4,10-16,11-64)
	TWBR = 0x02; //位率设置，fscl=cpu频率/(16+2*TWBR*预分频值)
	TWCR = (1<<TWEN); //开启TWI
}
void TWI_Start(void) //发送Start信号，开始本次TWI通信
{ TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);//发送Start信号
	while(!(TWCR&(1<<TWINT)));
	}
	void TWI_Stop(void)//发送Stop信号，结束本次TWI通信
	{TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);//发送Stop信号
	}
void TWI_Write(unsigned char uc_data) //向TWI接口发送8位数据
{
	TWDR = uc_data; //8位数据存放在TWDR
	TWCR = (1<<TWINT)|(1<<TWEN); //发送TWDR中的数据
	while(!(TWCR &(1<<TWINT))); //等待数据发出
}
unsigned char TWI_Read_With_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);//准备接收数据，并ACK
	while(!(TWCR &(1<<TWINT))); //等待接收数据
	return TWDR; //返回接收到的数据
}
unsigned char TWI_Read_With_NACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN); //准备接收数据，并NACK
	while(!(TWCR &(1<<TWINT))); //等待接收数据
	return TWDR; //返回接收到的数据
}
unsigned char TWI_Get_State_Info(void)
{
	unsigned char uc_status;
	uc_status = TWSR & 0xf8; //取状态寄存器高5位，低3位为0
	return uc_status; //返回状态寄存器高5位
}

#endif /* TWI_FUN_H_ */