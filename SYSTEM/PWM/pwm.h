/**
* @owner        Sharkespeara
* @file         pwm.h
* @brief        PWM头文件
* @details      
* @par History  见如下说明
*          
*/
#ifndef _PWM_H
#define _PWM_H

#include "stm32f10x.h" 

//使用前将需使用的定义取消注释

//#define EN_TIM1
//#define EN_TIM2
//#define EN_TIM3
//#define EN_TIM4
//#define EN_TIM5
//#define EN_TIM8

void TIM1_PWM_Init(u16 arr,u16 psc);
void TIM2_PWM_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM4_PWM_Init(u16 arr,u16 psc);
void TIM5_PWM_Init(u16 arr,u16 psc);
void TIM8_PWM_Init(u16 arr,u16 psc);

#endif
