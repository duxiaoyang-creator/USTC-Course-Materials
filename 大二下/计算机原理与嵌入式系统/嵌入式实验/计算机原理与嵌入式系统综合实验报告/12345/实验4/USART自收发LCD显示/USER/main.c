#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "string.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "12864.h"

extern u8  USART_RX_BUF[USART_REC_LEN]; 
extern u16 USART_RX_STA;  
extern u8 USART_TX_EN;
int sharedVar = 0;  // quanjubianliang
int main()
{

  char USART_SendBuf[]="count";
  int i;  
  int Len=strlen(USART_SendBuf);	

	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);
  lcd_GPIO_init();
	EXTIX_Init();       //初始化外部中断输入 
	LED_Init();				  //初始化LED端口  
	KEY_Init();

	Lcd_Init();
	uart1_init(115200);
	LED0=0;	

	
  while(1)
  {
		//LCD_Clear();			
		delay_ms(2000);
		if(USART_TX_EN)
		{
			for(i=0;i<Len;i++)
			{
				USART_SendData(USART1, USART_SendBuf[i]);         //向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=SET);//等待发送结束
			}
			USART_TX_EN=0;
			
		}

		if(USART_RX_STA==Len)
		 LCD_Display_Words(0,0,USART_RX_BUF);
	if(sharedVar%2 ==1)
	{
		 LCD_Display_Words(1,0,"odd number");
		LCD_Display_Words(3,0,"light:ON");
		delay_ms(2000);
		LCD_Clear();	
	}
	else
	{
		 LCD_Display_Words(2,0,"even number");
		LCD_Display_Words(3,0,"light:OFF");
		delay_ms(2000);
		LCD_Clear();	
	}
		
   }
}

