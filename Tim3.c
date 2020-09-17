#include "main.h"
#include "Tim3.h"



void Time3_Pwm_Init(u16 arr,u16 psc)
{
	RCC->APB1ENR  |= 1<<1;			//�򿪶�ʱ��3��ʱ��
	
	RCC->APB2ENR  |=1<<3;			  //�򿪶˿�B��ʱ��
	
	GPIOB->CRL &= 0xFF0FFFFF;		
	GPIOB->CRL |= 0x00B00000;		//��PA5����Ϊ�������
	
	RCC->APB2ENR  |= 1<<0;			//�򿪸���ʱ��
	
	AFIO->MAPR		&= ~(3<<10);	//���� MAPR ��[11:10]
	AFIO->MAPR 		|= 1<<11;
	
	TIM3->ARR = arr;						//�Զ���װ��ֵ
	TIM3->PSC = psc;						//Ԥ��Ƶ
	
	TIM3->CCMR1 |= 6<<12;				//����ΪPWM2ģʽ,ͨ��1
	
	TIM3->CCMR1 |= 1<<11;				//ʹ��Ԥװ�ؼĴ���,ͨ��1
	
	TIM3->CCER  |= 1<<4;				//���ʹ��,ͨ��1
	
	TIM3->CR1   |= 1<<7;				//�����Զ���װ�� 
	
	TIM3->CR1   |= 1<<0;				//ʹ�ܼ�����
	

}











