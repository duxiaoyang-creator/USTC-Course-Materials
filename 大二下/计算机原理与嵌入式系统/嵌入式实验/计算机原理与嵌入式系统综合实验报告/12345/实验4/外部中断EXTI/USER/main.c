#include "sys.h"
#include "delay.h"

#include "led.h"
#include "key.h"
#include "exti.h"


int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
  delay_init(168);    //初始化延时函数
	LED_Init();				  //初始化LED端口  
	KEY_Init();
	EXTIX_Init();       //初始化外部中断输入 
	LED0=0;					    
	while(1)
	{
  	
	}

}
