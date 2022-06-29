/**
* @owner        Sharkespeara
* @file         motor.c
* @brief        电机运动控制函数
* @details      
* @par History  见如下说明
*          
*/
#include "motor.h"
#include "sys.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*需修改*/
#define  LeftMotor_Go()			{GPIO_SetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Back()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_SetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Stop()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}

#define  RightMotor_Go()		{GPIO_SetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Back()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_SetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Stop()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}

#define  LeftMotorPWM(Speed)	TIM_SetCompare2(TIM4, Speed);
#define  RightMotorPWM(Speed)	TIM_SetCompare1(TIM4, Speed);		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
* Function       Car_Run
* @brief         小车前进
* @param[in]     Speed  
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Run(int Speed)
{
	LeftMotor_Go();
	RightMotor_Go();
	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}

/**
* Function       Car_Back
* @brief         小车后退
* @param[in]     Speed  
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Back(int Speed)
{
	LeftMotor_Back();
	RightMotor_Back();

	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}

/**
* Function       Car_Left 
* @brief         小车左转
* @param[in]     Speed  
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Left(int Speed)
{
	LeftMotor_Stop();
	RightMotor_Go();

	LeftMotorPWM(0);		  
	RightMotorPWM(Speed);		
}

/**
* Function       Car_Right 
* @brief         小车右转
* @param[in]     Speed  
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Right(int Speed)
{
	LeftMotor_Go();
	RightMotor_Stop();

	LeftMotorPWM(Speed);		  
	RightMotorPWM(0);		
}

/**
* Function       Car_Stop  
* @brief         小车刹车
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Stop(void)
{
	LeftMotor_Stop();
	RightMotor_Stop();

	LeftMotorPWM(0);		  
	RightMotorPWM(0);		
}

/**
* Function       Car_SpinLeft  
* @brief         小车左旋
* @param[in]     LeftSpeed：左电机速度  RightSpeed：右电机速度 
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_SpinLeft(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Back();
	RightMotor_Go();

	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);		
}

/**
* Function       Car_SpinRight  
* @brief         小车右旋
* @param[in]     LeftSpeed：左电机速度  RightSpeed：右电机速度 
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_SpinRight(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Go();
	RightMotor_Back();

	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);		
}
