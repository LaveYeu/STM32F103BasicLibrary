/**
* @owner        Sharkespeara
* @file         delay.h
* @brief        ��ʱ����ͷ�ļ�
* @details      
* @par History  ������˵��
*          
*/
#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h" 

void Tim2_init(void);
void delay_us (unsigned int a);
void delay_ms (unsigned int a);

#endif /*  _DELAY_H  */

