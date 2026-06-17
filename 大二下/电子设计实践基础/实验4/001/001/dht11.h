/*
 * dht11.h
 *
 * Created: 2025/4/11 18:35:11
 *  Author: dxydu
 */ 


#ifndef DHT11_H_
#define DHT11_H_
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
unsigned char byteReadDHT11(void) //从DHT11读取一个字节的数据
{ unsigned char oneBit,oneByte=0; //每次接收1位，最后完成8位接收并返回
	unsigned char i,uc_cnt; //循环变量，超时计数（脉冲宽度统计）
	for(i=0;i<8;i++) //接收8位数据，先接收的是最高位
	{ //1bit由50us的低电平开始，后跟26~28us的高电平为0，70us的高电平为1
		uc_cnt = 1; //超时计数初值，统计50us低电平
		while((PIND & (1<<PIND7))==0) //在50us的低电平
		{ uc_cnt++; //超时计数
			if(uc_cnt==0)break; } /*计数溢出：超时，跳过,while结束*/
			_delay_us(30); //跳过30us的高电平，如还是高电平收到‘1’，否则收到‘0’
			oneBit = 0; //假定收到‘0’
			if((PIND & (1<<PIND7))!=0)oneBit = 1; //还是高电平，收到‘1’
			uc_cnt = 1; //超时计数初值，统计70us高电平
			while((PIND & (1<<PIND7))!=0) //在70us的高电平
			{ uc_cnt++; if(uc_cnt==0)break; } /*计数溢出:超时，跳过,while结束*/
			oneByte <<=1; //收到1位后，之前收到的为高位，故左移一位
			oneByte|=oneBit; } /*新收到的合并到字节中*/ //for结束
			return oneByte; } /*返回收到的1字节*/ //函数结束
			void DHT11_Run(unsigned char * uc_data) //与DHT11通信的设置和数据传输等
			{ unsigned char uc_cnt; //超时计数（脉冲宽度统计）
				DDRD |=(1<<DDRD7); //PD7为输出模式
				PORTD &=~(1<<PORTD7); _delay_ms(20); //PD7输出0: 至少18ms的START信号
				PORTD |=(1<<PORTD7); _delay_us(20); //PD7输出1: 20us高电平
				DDRD &=~(1<<DDRD7); _delay_us(20); //PD7为输入模式，并等待DHT11响应
				if((PIND &(1<<PIND7))!=0)return; //DHT11没有响应
				uc_cnt = 1; //超时计数初值，统计80us低电平响应
				while((PIND & (1<<PIND7))==0) //在80us的低电平
				{ uc_cnt++; //超时计数
				if(uc_cnt==0)break;} //计数溢出：超时，跳过；while结束
				uc_cnt = 1; //超时计数初值，统计80us高电平响应
				while((PIND & (1<<PIND7))!=0) //在80us的高电平
				{ uc_cnt++; if(uc_cnt==0)break; } /*计数溢出：超时，跳过*/
				for(uc_cnt=0;uc_cnt<5;uc_cnt++) //接收DHT11发送的40位温湿度数据
				{ uc_data[uc_cnt]=byteReadDHT11(); } //0-湿度整/小数,温度整/小数,校验-4
			}



#endif /* DHT11_H_ */