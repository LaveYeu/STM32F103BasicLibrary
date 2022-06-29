/**
* @owner        Sharkespeara
* @file         PID.c
* @brief        PID控制函数
* @details      
* @par History  见如下说明
*          
*/

#include "control.h"
#include "Linewalking.h"
#include "motor.h"

//*************************************************************************
//变量定义
float RES_PWM1,RES_PWM2,RES_PWM3,RES_PWM4;//定义PWM输出量
int Speed1=0,Speed2=0,Speed3=0,Speed4=0;          //定义目标速度值
int LAST1 = 0,LAST2 = 0,LAST3 = 0,LAST4 = 0;      //定义实际速度值
extern int speed1,speed2,speed3;
extern float temp1_val;
int speedd1,speedd2,speedd3,speedd4;


//*************************************************************************


//*************************************************************************

//*************************************************************************
//中断
void PID_TIM6_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;	
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Period = arr;     //重装载值
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;  //预分频系数
	TIM_TimeBaseInitStruct.TIM_ClockDivision =0; //时钟分割
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; //TIM向上计数模式
	TIM_TimeBaseInit(TIM6,&TIM_TimeBaseInitStruct);
	
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);  //使能定时器中断
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM6_IRQn; 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0; 
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x01; 
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
  TIM_ClearFlag(TIM6, TIM_FLAG_Update);//清除TIM的更新标志位
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);//使能定时器中断

	TIM_Cmd(TIM6,ENABLE);	
}

//第一电机PID
//**************************************************************************
//**************************************************************************
PID pid1;
void PID_param1_init(void)
 {
     /* 初始化参数 */
     pid1.target_val = 0;           //目标值
     pid1.actual_val = 0.0;         //实际值
     pid1.err        = 0;           //定义误差值
  	 pid1.output_val = 0;           //定义输出量
     pid1.err_last   = 0.0;         //定义上一个偏差值
     pid1.integral   = 0.0;         //定义积分值
     pid1.Kp         = 0;           //参数
     pid1.Ki         = 0;           //参数
     pid1.Kd         = 0;           //参数
	   pid1.tracking   = 0;           //循迹偏移量
 }

//**************************************************
float PID_realize1(float actual1_val)
{
     /*计算目标值与实际值的误差*/
    pid1.err = pid1.target_val - actual1_val;
     /*误差累积*/
    pid1.integral += pid1.err;
     /*PID算法实现*/
    pid1.output_val = (pid1.Kp*pid1.err  + pid1.tracking)+
										 pid1.Ki*pid1.integral+
										 pid1.Kd*(pid1.err-pid1.err_last);
     /*误差传递*/
    pid1.err_last = pid1.err;
     /*返回当前实际值*/
    return pid1.output_val;
}
//**************************************************
void PID_TARGET_1(float temp1_val)
{
	pid1.target_val = temp1_val;    // 设置当前的目标值
	RES_PWM1 = PID_realize1(LAST1);//通过PID计算所需PWM值
  Load1(RES_PWM1);                //装载PWM值
}
//**************************************************************************
//**************************************************************************



//第二电机PID
//**************************************************************************
//**************************************************************************
PID pid2;
void PID_param2_init(void)
 {
     /* 初始化参数 */
     pid2.target_val = 0;           //目标值
     pid2.actual_val = 0.0;         //实际值
     pid2.err        = 0;           //定义误差值
  	 pid2.output_val = 0;           //定义输出量
     pid2.err_last   = 0.0;         //定义上一个偏差值
     pid2.integral   = 0.0;         //定义积分值
     pid2.Kp         = 0;           //参数
     pid2.Ki         = 0;           //参数
     pid2.Kd         = 0;           //参数
	   pid2.tracking   = 0;           //循迹偏移量
 }

//**************************************************
float PID_realize2(float actual2_val)
{
     /*计算目标值与实际值的误差*/
    pid2.err = pid2.target_val - actual2_val;
     /*误差累积*/
    pid2.integral += pid2.err;
     /*PID算法实现*/
    pid2.output_val = (pid2.Kp*pid2.err  + pid2.tracking)+
										 pid2.Ki*pid2.integral+
										 pid2.Kd*(pid2.err-pid2.err_last);
     /*误差传递*/
    pid2.err_last = pid2.err;
     /*返回当前实际值*/
    return pid2.output_val;
}
//**************************************************
void PID_TARGET_2(float temp2_val)
{
	pid2.target_val = temp2_val;    // 设置当前的目标值
	RES_PWM2 = PID_realize2(LAST2);//通过PID计算所需PWM值
  Load2(RES_PWM2);                //装载PWM值
}
//**************************************************************************
//**************************************************************************




//第三电机PID
//**************************************************************************
//**************************************************************************
PID pid3;
void PID_param3_init(void)
 {
     /* 初始化参数 */
     pid3.target_val = 0;           //目标值
     pid3.actual_val = 0.0;         //实际值
     pid3.err        = 0;           //定义误差值
  	 pid3.output_val = 0;           //定义输出量
     pid3.err_last   = 0.0;         //定义上一个偏差值
     pid3.integral   = 0.0;         //定义积分值
     pid3.Kp         = 0;           //参数
     pid3.Ki         = 0;           //参数
     pid3.Kd         = 0;           //参数
	   pid3.tracking   = 0;           //循迹偏移量
 }

//**************************************************
float PID_realize3(float actual3_val)
{
     /*计算目标值与实际值的误差*/
    pid3.err = pid3.target_val - actual3_val;
     /*误差累积*/
    pid3.integral += pid3.err;
     /*PID算法实现*/
    pid3.output_val = (pid3.Kp*pid3.err  + pid3.tracking)+
										 pid3.Ki*pid3.integral+
										 pid3.Kd*(pid3.err-pid3.err_last);
     /*误差传递*/
    pid3.err_last = pid3.err;
     /*返回当前实际值*/
    return pid3.output_val;
}
//**************************************************
void PID_TARGET_3(float temp3_val)
{
	pid3.target_val = temp3_val;    // 设置当前的目标值
	RES_PWM3 = PID_realize3(LAST3);//通过PID计算所需PWM值
  Load3(RES_PWM3);                //装载PWM值
}
//**************************************************************************
//**************************************************************************




//第四电机PID
//**************************************************************************
//**************************************************************************
PID pid4;
void PID_param4_init(void)
 {
     /* 初始化参数 */
     pid4.target_val = 0;           //目标值
     pid4.actual_val = 0.0;         //实际值
     pid4.err        = 0;           //定义误差值
  	 pid4.output_val = 0;           //定义输出量
     pid4.err_last   = 0.0;         //定义上一个偏差值
     pid4.integral   = 0.0;         //定义积分值
     pid4.Kp         = 0;           //参数
     pid4.Ki         = 0;           //参数
     pid4.Kd         = 0;           //参数
	   pid4.tracking   = 0;           //循迹偏移量
 }

//**************************************************
float PID_realize4(float actual4_val)
{
     /*计算目标值与实际值的误差*/
    pid4.err = pid4.target_val - actual4_val;
     /*误差累积*/
    pid4.integral += pid4.err;
     /*PID算法实现*/
    pid4.output_val = (pid4.Kp*pid4.err  + pid4.tracking)+
										 pid4.Ki*pid4.integral+
										 pid4.Kd*(pid4.err-pid4.err_last);
     /*误差传递*/
    pid4.err_last = pid4.err;
     /*返回当前实际值*/
    return pid4.output_val;
}
//**************************************************
void PID_TARGET_4(float temp4_val)
{
	pid4.target_val = temp4_val;    // 设置当前的目标值
	RES_PWM4 = PID_realize4(LAST4);//通过PID计算所需PWM值
  Load4(RES_PWM4);                //装载PWM值
}
//**************************************************************************
//**************************************************************************



//中断执行
int TIM6_IRQHandler(void) //PID中断输入引脚
{
	 
	if(TIM_GetFlagStatus(TIM6,TIM_FLAG_Update)==SET)//一级判定
	{
		  LAST1 = TIM2->CNT - 32768; //瞬时速度值
			LAST2 = TIM3->CNT - 32768;
			LAST3 = TIM4->CNT	- 32768;
      LAST4 = TIM5->CNT	- 32768;

		  TIM2->CNT = 32768;          //CNT值复位
			TIM2->CNT = 32768;         
			TIM3->CNT = 32768;
			TIM4->CNT = 32768;
		
			PID_TARGET_1(speed1);     //设置PID速度
			PID_TARGET_2(speed2);
			PID_TARGET_3(speed3);
      PID_TARGET_4(speed4);
	} 
	TIM_ClearITPendingBit(TIM6,TIM_IT_Update);//清除中断标志位
	
	return 0;
}













