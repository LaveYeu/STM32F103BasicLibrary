/**
* @owner        Sharkespeara
* @file         motor.h
* @brief        电机控制头文件
* @details      
* @par History  见如下说明
*          
*/
#ifndef _MOTOR_H__
#define _MOTOR_H__

#include "stm32f10x.h"


#define Motor_RCC		     RCC_APB2Periph_GPIOB
#define Motor_Port		   GPIOB
#define Left_MotoA_Pin 	 GPIO_Pin_9
#define Left_MotoB_Pin 	 GPIO_Pin_8

#define Right_MotoA_Pin	 GPIO_Pin_4
#define Right_MotoB_Pin  GPIO_Pin_5

void Car_Run(int Speed);
void Car_Back(int Speed);
void Car_Left(int Speed);
void Car_Right(int Speed);
void Car_Stop(void);

void Car_SpinStop(void);
void Car_SpinLeft(int LeftSpeed, int RightSpeed);
void Car_SpinRight(int LeftSpeed, int RightSpeed);

void Motor_PWM_Init(u16 arr, u16 psc, u16 arr2, u16 psc2);

#endif
