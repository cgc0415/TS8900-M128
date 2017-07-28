//延时程序2012年1月15日16:50:49
#include"config.h"
//1us延时程序
void delay_1us(void)
{
 	 asm("nop");
}

//Nus延时程序
void delay_nus(unsigned int n)
{
 	 unsigned int i=0;
	 for(i=0;i<n;i++)
	 delay_1us();
}

//1ms延时程序
void delay_1ms(void)
{
 	 unsigned int i=0;
	 for(i=0;i<1140;i++);
}

//N ms延时程序
void delay_nms(unsigned int n)
{
 	 unsigned int i=0;
	 for(i=0;i<n;i++)
	 delay_1ms();
}