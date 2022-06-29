/**
* @owner        Sharkespeara
* @file         PID.h
* @brief        PID头文件
* @details      
* @par History
*          
*/
#ifndef  _CONTROL_H
#define  _CONTROL_H

#include "sys.h" 

typedef struct 
 {
     float target_val;  //----> 目标值       		
     float actual_val;  //----> 实际值              
	 float output_val;  //----> PID计算完输出量                
     float err;         //----> 误差值                
     float err_last;    //----> 上一次误差值                
     float Kp,Ki,Kd;    //----> PID参数                
     float integral;    //----> 误差累积              
	 float tracking;    //----> 循迹偏移量              
}PID;

void EXTI2_IRQHandler(void);

void PID_TIM6_Init(u16 arr,u16 psc);
void PID_param1_init(void);
void PID_param2_init(void);
void PID_param3_init(void);

float PID_realize1(float actual1_val);
float PID_realize2(float actual2_val);
float PID_realize3(float actual3_val);
float PID_realize4(float actual4_val);


void PID_TARGET_1(float temp1_val);
void PID_TARGET_2(float temp2_val);
void PID_TARGET_3(float temp3_val);
void PID_TARGET_4(float temp4_val);

#endif

