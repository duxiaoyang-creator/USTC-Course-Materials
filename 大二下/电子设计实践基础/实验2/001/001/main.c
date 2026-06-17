#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char counter = 0; // 次数

int main(void)
{
	unsigned char seg7_hex[16] =
	{0xfc, 0x60, 0xda, 0xf2, 0x66, 0xb6, 0xbe, 0xe0,
	0xfe, 0xf6, 0xee, 0x3e, 0x9c, 0x7a, 0x9e, 0x8e}; // MSB-a,b,…,dp-LSB

	DDRB = 0xff; // PB7~0为输出，分别控制七段数码管的a~g,dp
	DDRC = 0x01; // PC0为输出，控制数码管的共阴极管脚(如DIG1等)
	PORTC = 0x00; // PC0输出低电平‘0’
	
	// 配置INT1中断
	DDRD &= ~(1 << DDD3); // PD3 (INT1) 为输入（从tp223触摸开关）
	MCUCR |= (1 << ISC11) | (1 << ISC10); // INT1 上升沿触发中断
	GICR |= (1 << INT1); // 开启 INT1 中断
	sei(); // 开启全局中断 SREG (I)

	while (1)
	{
		PORTB = seg7_hex[counter]; // 更新数码管显示
	}
} // main函数结束

ISR(INT1_vect) // INT1中断向量
{
	if (counter < 4)
	counter++; // 增加计数
	else
	counter = 0; // 重置计数
}
