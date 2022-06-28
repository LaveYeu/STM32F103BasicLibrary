/*
* @owner        Sharkespeara
* @file         GPIO.h
* @brief        
* @details      
* @par History  
*          
*/

#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm32f10x.h"

//#define EN_GPIOA
//#define EN_GPIOB
//#define EN_GPIOC 
//#define EN_GPIOD 
//#define EN_GPIOE 
//#define EN_GPIOF 

void GPIO_SITEA(void);
void GPIO_SITEB(void);
void GPIO_SITEC(void);
void GPIO_SITED(void);
void GPIO_SITEE(void);
void GPIO_SITEF(void);

#endif
/*
����ģʽ

    -���븡�գ�GPIO_Mode_IN_FLOATING��

    -��������(GPIO_Mode_IPU)

    -��������(GPIO_Mode_IPD)

    -ģ������(GPIO_Mode_AIN)

���ģʽ

    -��©���(GPIO_Mode_Out_OD)

    -��©���ù���(GPIO_Mode_AF_OD)

    -����ʽ���(GPIO_Mode_Out_PP)

    -����ʽ���ù���(GPIO_Mode_AF_PP)
*/
