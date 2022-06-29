/**
* @owner        Sharkespeara
* @file         PID.h
* @brief        PIDͷ�ļ�
* @details      
* @par History
*          
*/
#ifndef  _CONTROL_H
#define  _CONTROL_H

#include "sys.h" 

typedef struct 
 {
     float target_val;  //----> Ŀ��ֵ       		
     float actual_val;  //----> ʵ��ֵ              
	 float output_val;  //----> PID�����������                
     float err;         //----> ���ֵ                
     float err_last;    //----> ��һ�����ֵ                
     float Kp,Ki,Kd;    //----> PID����                
     float integral;    //----> ����ۻ�              
	 float tracking;    //----> ѭ��ƫ����              
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

