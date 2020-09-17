#include "main.h"
#include "Tim3.h"



void Time3_Pwm_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR  |= 1<<1;			//打开定时器3的时钟
	
	RCC->APB2ENR  |=1<<3;			  //打开端口B的时钟
	
	GPIOB->CRL &= 0xFF0FFFFF;		
	GPIOB->CRL |= 0x00B00000;		//将PA5配置为复用输出
	
	RCC->APB2ENR  |= 1<<0;			//打开辅助时钟
	
	AFIO->MAPR		&= ~(3<<10);	//清零 MAPR 的[11:10]
	AFIO->MAPR 		|= 1<<11;
	
	TIM3->ARR = arr;						//自动重装载值
	TIM3->PSC = psc;						//预分频
	
	TIM3->CCMR1 |= 6<<12;				//配置为PWM2模式,通道1
	
	TIM3->CCMR1 |= 1<<11;				//使能预装载寄存器,通道1
	
	TIM3->CCER  |= 1<<4;				//输出使能,通道1
	
	TIM3->CR1   |= 1<<7;				//允许自动重装载 
	
	TIM3->CR1   |= 1<<0;				//使能计数器
	

}











