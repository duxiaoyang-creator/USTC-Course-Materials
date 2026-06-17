#include "12864.h"
#include "delay.h"


 
void lcd_GPIO_init()
{
       
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG|RCC_AHB1Periph_GPIOF, ENABLE);//使能GPIOF时钟

  //GPIOF14,F15初始化设置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);
	 
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//普通输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOG, &GPIO_InitStructure);		
	
	CS=1;	
  SID=1;
  SCLK=1;
}

/* 字符显示RAM地址    4行8列 */



void SendByte(u8 byte)
{
     u8 i; 
	  for(i = 0;i < 8;i++)
    {
			//SCLK = 0;
			if((byte << i) & 0x80)  //0x80(1000 0000)  只会保留最高位
			{
				SID = 1;           // 引脚输出高电平，代表发送1
			}
			else
			{
				SID = 0;         // 引脚输出低电平，代表发送0
			}
			//delay_us(5);
			//SCLK = 1; 
		
			SCLK = 0;   //时钟线置低  允许SID变化
			delay_us(5); //延时使数据写入
			SCLK = 1;    //拉高时钟，让从机读SID
			
		}   
}



void Lcd_WriteCmd(u8 Cmd )
{
     delay_ms(1);     //由于我们没有写LCD正忙的检测，所以直接延时1ms，使每次写入数据或指令间隔大于1ms 便可不用写忙状态检测
     SendByte(WRITE_CMD);            //11111,RW(0),RS(0),0   
     SendByte(0xf0&Cmd);      //高四位
     SendByte(Cmd<<4);   //低四位(先执行<<)
}


void Lcd_WriteData(u8 Dat )
{
     delay_ms(1);     
     SendByte(WRITE_DAT);            //11111,RW(0),RS(1),0
     SendByte(0xf0&Dat);      //高四位
     SendByte(Dat<<4);   //低四位(先执行<<)
}

void Lcd_Init(void)
{ 
delay_ms(50);   	//等待液晶自检（延时>40ms）
	Lcd_WriteCmd(0x30);        //功能设定:选择基本指令集
delay_ms(1);//延时>100us
	Lcd_WriteCmd(0x30);        //功能设定:选择8bit数据流
delay_ms(1);	//延时>37us
    Lcd_WriteCmd(0x0c);        //开显示
delay_ms(1);	//延时>100us
    Lcd_WriteCmd(0x01);        //清除显示，并且设定地址指针为00H
delay_ms(30);	//延时>10ms
		Lcd_WriteCmd(0x06);        //进入设定点，初始化完成
}



void LCD_Display_Words(uint8_t x,uint8_t y,uint8_t*str)
{ 
	Lcd_WriteCmd(LCD_addr[x][y]); //写初始光标位置
	while(*str>0)
    { 
      Lcd_WriteData(*str);    //写数据
      str++;     
    }
}

void LCD_Display_Picture(uint8_t *img)
{
		uint8_t x,y,i;
		Lcd_WriteCmd(0x34);		//切换到扩充指令
		Lcd_WriteCmd(0x34);		//关闭图形显示
		for(i = 0; i < 2; i++)   //上下屏写入
		{
			for(y=0;y<32;y++)   //垂直Y写32次
			{  
				for(x=0;x<8;x++)   //横向X写8次
				{
					Lcd_WriteCmd(0x80 + y);		//行地址
					Lcd_WriteCmd(0x80 + x+i*0x08);		//列地址
					Lcd_WriteData(*img ++);		//写高位字节数据 D15－D8   
					Lcd_WriteData(*img ++);		//写低位字节数据 D7－D0
				}
			}
		}
		Lcd_WriteCmd(0x36);//打开图形显示		
		Lcd_WriteCmd(0x30);        //切换回基本指令
}	

void LCD_Clear(void)
{
		Lcd_WriteCmd(0x01);			//清屏指令
		delay_ms(2);				//延时以待液晶稳定【至少1.6ms】
}
	
