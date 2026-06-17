/*
 * 001.c
 *
 * Created: 2025/5/7 18:22:18
 * Author : dxydu
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "twi_lcd.h"
#define MAX_TASKS 3
typedef struct {
	void(*ftask)(void); //指向函数的指针，即要执行的任务
	int ticks; //执行此任务的时间间隔
}OSTASK; //任务的结构体类型，方便处理
// 定义3个任务
unsigned char tp_cnt=0; //统计触摸开关的开关次数
void tp_task() //统计触摸开关的开关次数
{ static unsigned char tp1=0,tp2=0; //读取开关的状态，保留上一次结果
	DDRB &= ~(1<<DDRB0); //PB0管脚连接触摸开关的开关信号
	tp2 = tp1; //缓存
	tp1 = (PINB & (1<<PINB0)); //读取PB0管脚的状态
	if(tp2==0 && tp1==1)tp_cnt++; //统计开关次数
}
void Rgb_show()
{ DDRC |=(1<<DDRC0)|(1<<DDRC1)|(1<<DDRC2); //为输出
	switch(tp_cnt) { //根据触摸开关的开关次数点亮LED
		case 0: PORTC |=(1<<PORTC0);break;
		case 2: PORTC |=(1<<PORTC1);break;
		case 4: PORTC |=(1<<PORTC2);break;
		case 1: PORTC &=~(1<<PORTC0);break;
		case 3: PORTC &=~(1<<PORTC1);break;
		case 5: PORTC &=~(1<<PORTC2);break;
		case 6: PORTC |=(1<<PORTC0);break;
		case 7: PORTC |=(1<<PORTC1);break;
		case 8: PORTC |=(1<<PORTC2);break;
		case 9: PORTC &=~(1<<PORTC2);break;
		default:tp_cnt=0; break;
	}
}
void lcd_show()
{ char ch[5]={'0'},i; //
unsigned char t=tp_cnt;
for(i=0;i<3;i++)
{ ch[2-i]=t%10+48; //数字转换为字符
t/=10; } //去掉低位
cli(); //全局中断关，不然会影响显示过程，定时器0的中断也停止了
LCD_Write_String(0,1,"times:");
LCD_Write_String(0,8,ch);
sei(); //全局中断开
}
int ticks[MAX_TASKS]={3,7,19}; //对应于任务执行间隔（时间片），单位1ms
 OSTASK runtask[MAX_TASKS]= {{tp_task,3},{Rgb_show,7},{lcd_show,19}};//任务与执行时间操作列表，方便循环处理
int main(void)
{ unsigned char i=0;
	TWI_Init(); LCD_Init(); //lcd1602初始化
	//定时器0的初始化：1ms的定时与中断，用做时间片基准，中断定时等
	TCNT0 = 131; //1MHz的8分频，从131计数到255中断一次正好1ms
	TIMSK = (1<<TOIE0) ; //定时器0的溢出中断开
	TCCR0 = (1<<CS01); //CPU时钟的8分频，定时器0开始工作
	sei(); //全局中断开
	while (1) {
		for(i=0;i<MAX_TASKS;i++) { //调度
			if(runtask[i].ticks==0) { //到达此任务的执行（时间片耗尽）
				runtask[i].ticks=ticks[i]; //恢复此任务的时间片
			runtask[i].ftask(); } //执行相应的任务
		}
		for(i=0;i<100;i++); /*延时*/
	} } //while和main结束
	
	ISR(TIMER0_OVF_vect) {
			TCNT0 = 131;            // 初始值，1ms后溢出
			TIMSK = (1<<TOIE0);    // 开启定时器0溢出中断
			TCCR0 = (1<<CS01);     // 8分频，启动定时器         
		for (uint8_t i=0; i<MAX_TASKS; i++) {
			if (runtask[i].ticks > 0) runtask[i].ticks--; // 时间片递减
		}
	}
	
