/*
 * hcsr04.h
 *
 * Created: 2025/4/11 18:48:52
 *  Author: dxydu
 */ 

#ifndef HC_SR04_H_
#define HC_SR04_H_
#ifndef F_CPU
#define F_CPU 1000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>
unsigned int HCSR04_Run(void)
{ unsigned int i_cnt=0; //统计echo的高电平(固定时钟下的次数)
	unsigned int uc_cnt=1; //超时计数（统计在一定时间内没有响应）
	/*为了测量的准确，如系统中使用了中断，这里要禁止中断 cli(); */
	DDRD |= (1<<DDRD6); //PD6为输出（到HC_SR04的Trig管脚）
	DDRD &= ~(1<<DDRD5); //PD5为输入（来自HC_SR04的Echo管脚）
	PORTD |=(1<<PORTD6); //PD6输出高电平到Trig告诉HC_SR04准备发送超声波
	_delay_us(20); //持续20us(>10us)
	PORTD &=~(1<<PORTD6); //PD6输出低电平到Trig结束通知
	while((PIND&(1<<PIND5))==0) //等待Echo为高电平(即收到超声回波)
	{ uc_cnt++; if(uc_cnt>9000)break; } //计数溢出：超时，跳过
	i_cnt = 2; //统计Echo初值=检测到echo信号+循环的判断约2个CPU时钟周期
	while((PIND&(1<<PIND5))!=0) //继续统计ECHO信号高电平的持续时间
	i_cnt++; //每次=数据加载+&运算+判断+循环+加约5个时钟周期（默认1MHz）
	/*若之前禁用了中断，这里可以开中断了 sei();*/
return(i_cnt*5.0/100.0*17.0); } //返回距离，单位mm
#endif /* HC_SR04_H_ */
