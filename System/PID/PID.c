/**
* @owner        Sharkespeara
* @file         PID.c
* @brief        PID���ƺ���
* @details      
* @par History  ������˵��
*          
*/

#include "control.h"
#include "Linewalking.h"
#include "motor.h"

//*************************************************************************
//��������
float RES_PWM1,RES_PWM2,RES_PWM3,RES_PWM4;//����PWM�����
int Speed1=0,Speed2=0,Speed3=0,Speed4=0;          //����Ŀ���ٶ�ֵ
int LAST1 = 0,LAST2 = 0,LAST3 = 0,LAST4 = 0;      //����ʵ���ٶ�ֵ
extern int speed1,speed2,speed3;
extern float temp1_val;
int speedd1,speedd2,speedd3,speedd4;


//*************************************************************************


//*************************************************************************

//*************************************************************************
//�ж�
void PID_TIM6_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Period = arr;     //��װ��ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;  //Ԥ��Ƶϵ��
	TIM_TimeBaseInitStruct.TIM_ClockDivision =0; //ʱ�ӷָ�
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitStruct);
	
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);  //ʹ�ܶ�ʱ���ж�
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn; 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; 
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
  TIM_ClearFlag(TIM6, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);//ʹ�ܶ�ʱ���ж�

	TIM_Cmd(TIM6,ENABLE);	
}

//��һ���PID
//**************************************************************************
//**************************************************************************
PID pid1;
void PID_param1_init(void)
 {
     /* ��ʼ������ */
     pid1.target_val = 0;           //Ŀ��ֵ
     pid1.actual_val = 0.0;         //ʵ��ֵ
     pid1.err        = 0;           //�������ֵ
  	 pid1.output_val = 0;           //���������
     pid1.err_last   = 0.0;         //������һ��ƫ��ֵ
     pid1.integral   = 0.0;         //�������ֵ
     pid1.Kp         = 0;           //����
     pid1.Ki         = 0;           //����
     pid1.Kd         = 0;           //����
	   pid1.tracking   = 0;           //ѭ��ƫ����
 }

//**************************************************
float PID_realize1(float actual1_val)
{
     /*����Ŀ��ֵ��ʵ��ֵ�����*/
    pid1.err = pid1.target_val - actual1_val;
     /*����ۻ�*/
    pid1.integral += pid1.err;
     /*PID�㷨ʵ��*/
    pid1.output_val = (pid1.Kp*pid1.err  + pid1.tracking)+
										 pid1.Ki*pid1.integral+
										 pid1.Kd*(pid1.err-pid1.err_last);
     /*����*/
    pid1.err_last = pid1.err;
     /*���ص�ǰʵ��ֵ*/
    return pid1.output_val;
}
//**************************************************
void PID_TARGET_1(float temp1_val)
{
	pid1.target_val = temp1_val;    // ���õ�ǰ��Ŀ��ֵ
	RES_PWM1 = PID_realize1(LAST1);//ͨ��PID��������PWMֵ
  Load1(RES_PWM1);                //װ��PWMֵ
}
//**************************************************************************
//**************************************************************************



//�ڶ����PID
//**************************************************************************
//**************************************************************************
PID pid2;
void PID_param2_init(void)
 {
     /* ��ʼ������ */
     pid2.target_val = 0;           //Ŀ��ֵ
     pid2.actual_val = 0.0;         //ʵ��ֵ
     pid2.err        = 0;           //�������ֵ
  	 pid2.output_val = 0;           //���������
     pid2.err_last   = 0.0;         //������һ��ƫ��ֵ
     pid2.integral   = 0.0;         //�������ֵ
     pid2.Kp         = 0;           //����
     pid2.Ki         = 0;           //����
     pid2.Kd         = 0;           //����
	   pid2.tracking   = 0;           //ѭ��ƫ����
 }

//**************************************************
float PID_realize2(float actual2_val)
{
     /*����Ŀ��ֵ��ʵ��ֵ�����*/
    pid2.err = pid2.target_val - actual2_val;
     /*����ۻ�*/
    pid2.integral += pid2.err;
     /*PID�㷨ʵ��*/
    pid2.output_val = (pid2.Kp*pid2.err  + pid2.tracking)+
										 pid2.Ki*pid2.integral+
										 pid2.Kd*(pid2.err-pid2.err_last);
     /*����*/
    pid2.err_last = pid2.err;
     /*���ص�ǰʵ��ֵ*/
    return pid2.output_val;
}
//**************************************************
void PID_TARGET_2(float temp2_val)
{
	pid2.target_val = temp2_val;    // ���õ�ǰ��Ŀ��ֵ
	RES_PWM2 = PID_realize2(LAST2);//ͨ��PID��������PWMֵ
  Load2(RES_PWM2);                //װ��PWMֵ
}
//**************************************************************************
//**************************************************************************




//�������PID
//**************************************************************************
//**************************************************************************
PID pid3;
void PID_param3_init(void)
 {
     /* ��ʼ������ */
     pid3.target_val = 0;           //Ŀ��ֵ
     pid3.actual_val = 0.0;         //ʵ��ֵ
     pid3.err        = 0;           //�������ֵ
  	 pid3.output_val = 0;           //���������
     pid3.err_last   = 0.0;         //������һ��ƫ��ֵ
     pid3.integral   = 0.0;         //�������ֵ
     pid3.Kp         = 0;           //����
     pid3.Ki         = 0;           //����
     pid3.Kd         = 0;           //����
	   pid3.tracking   = 0;           //ѭ��ƫ����
 }

//**************************************************
float PID_realize3(float actual3_val)
{
     /*����Ŀ��ֵ��ʵ��ֵ�����*/
    pid3.err = pid3.target_val - actual3_val;
     /*����ۻ�*/
    pid3.integral += pid3.err;
     /*PID�㷨ʵ��*/
    pid3.output_val = (pid3.Kp*pid3.err  + pid3.tracking)+
										 pid3.Ki*pid3.integral+
										 pid3.Kd*(pid3.err-pid3.err_last);
     /*����*/
    pid3.err_last = pid3.err;
     /*���ص�ǰʵ��ֵ*/
    return pid3.output_val;
}
//**************************************************
void PID_TARGET_3(float temp3_val)
{
	pid3.target_val = temp3_val;    // ���õ�ǰ��Ŀ��ֵ
	RES_PWM3 = PID_realize3(LAST3);//ͨ��PID��������PWMֵ
  Load3(RES_PWM3);                //װ��PWMֵ
}
//**************************************************************************
//**************************************************************************




//���ĵ��PID
//**************************************************************************
//**************************************************************************
PID pid4;
void PID_param4_init(void)
 {
     /* ��ʼ������ */
     pid4.target_val = 0;           //Ŀ��ֵ
     pid4.actual_val = 0.0;         //ʵ��ֵ
     pid4.err        = 0;           //�������ֵ
  	 pid4.output_val = 0;           //���������
     pid4.err_last   = 0.0;         //������һ��ƫ��ֵ
     pid4.integral   = 0.0;         //�������ֵ
     pid4.Kp         = 0;           //����
     pid4.Ki         = 0;           //����
     pid4.Kd         = 0;           //����
	   pid4.tracking   = 0;           //ѭ��ƫ����
 }

//**************************************************
float PID_realize4(float actual4_val)
{
     /*����Ŀ��ֵ��ʵ��ֵ�����*/
    pid4.err = pid4.target_val - actual4_val;
     /*����ۻ�*/
    pid4.integral += pid4.err;
     /*PID�㷨ʵ��*/
    pid4.output_val = (pid4.Kp*pid4.err  + pid4.tracking)+
										 pid4.Ki*pid4.integral+
										 pid4.Kd*(pid4.err-pid4.err_last);
     /*����*/
    pid4.err_last = pid4.err;
     /*���ص�ǰʵ��ֵ*/
    return pid4.output_val;
}
//**************************************************
void PID_TARGET_4(float temp4_val)
{
	pid4.target_val = temp4_val;    // ���õ�ǰ��Ŀ��ֵ
	RES_PWM4 = PID_realize4(LAST4);//ͨ��PID��������PWMֵ
  Load4(RES_PWM4);                //װ��PWMֵ
}
//**************************************************************************
//**************************************************************************



//�ж�ִ��
int TIM6_IRQHandler(void) //PID�ж���������
{
	 
	if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)==SET)//һ���ж�
	{
		  LAST1 = TIM2->CNT - 32768; //˲ʱ�ٶ�ֵ
			LAST2 = TIM3->CNT - 32768;
			LAST3 = TIM4->CNT	- 32768;
      LAST4 = TIM5->CNT	- 32768;

		  TIM2->CNT = 32768;          //CNTֵ��λ
			TIM2->CNT = 32768;         
			TIM3->CNT = 32768;
			TIM4->CNT = 32768;
		
			PID_TARGET_1(speed1);     //����PID�ٶ�
			PID_TARGET_2(speed2);
			PID_TARGET_3(speed3);
      PID_TARGET_4(speed4);
	} 
	TIM_ClearITPendingBit(TIM6,TIM_IT_Update);//����жϱ�־λ
	
	return 0;
}













