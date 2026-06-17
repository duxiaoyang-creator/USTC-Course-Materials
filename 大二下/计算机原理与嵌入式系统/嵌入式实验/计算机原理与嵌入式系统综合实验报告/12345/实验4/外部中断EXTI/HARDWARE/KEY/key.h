#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 
 

/*下面的方式是通过直接操作库函数方式读取IO*/
#define KEY0 		GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0) //PE0








void KEY_Init(void);	//IO初始化


#endif
