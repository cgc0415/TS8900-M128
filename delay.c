//��ʱ����2012��1��15��16:50:49
#include"config.h"
//1us��ʱ����
void delay_1us(void)
{
 	 asm("nop");
}

//Nus��ʱ����
void delay_nus(unsigned int n)
{
 	 unsigned int i=0;
	 for(i=0;i<n;i++)
	 delay_1us();
}

//1ms��ʱ����
void delay_1ms(void)
{
 	 unsigned int i=0;
	 for(i=0;i<1140;i++);
}

//N ms��ʱ����
void delay_nms(unsigned int n)
{
 	 unsigned int i=0;
	 for(i=0;i<n;i++)
	 delay_1ms();
}