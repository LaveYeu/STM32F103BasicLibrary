/**
* @owner        Sharkespeara
* @file         delay.c
* @brief        延时函数
* @details      
* @par History  见如下说明
*          
*/
#include "stm32f10x.h" 
#include "delay.h"


void Tim2_init(void)
{
	
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_TimeBaseInitStruct.TIM_Period = 4-1;
	TIM_TimeBaseInitStruct.TIM_Prescaler = 18-1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	TIM_Cmd(TIM2, ENABLE);
	
}

void delay_us(unsigned int a)
{
	unsigned int b;
	b = 0;
	TIM_SetCounter(TIM2, 0);
	while (b <= a)
	{
		if(TIM_GetFlagStatus(TIM2, TIM_FLAG_Update) == SET)
		{
			b++;
			TIM_ClearFlag(TIM2, TIM_FLAG_Update);
		}
	}
}

void delay_ms(unsigned int a)
{
		delay_us (1000*a);
}
