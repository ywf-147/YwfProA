#include "main.h"
#include <led.h>


void led_init(void)
{
	RCC->APB2ENR  |=1<<3;
	GPIOB->CRH		&=0xFFFFFF0F;
	GPIOB->CRH		|=0x00000030;

}










