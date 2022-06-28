/*
* @owner        Sharkespeara
* @file         Comopenmv.h
* @brief        openmv通信头文件
* @details      
* @par History  见如下说明
*          
*/

#ifndef _Comopenmv_H_
#define _Comopenmv_H_

#include "stm32f10x.h"



void Optical_Flow_Receive_Prepare(u8 data);
void Data_Processing(u8 *data_buf,u8 num);



#endif