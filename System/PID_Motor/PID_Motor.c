#include "motor.h"
#include "control.h"
#include "linewalking.h"

///////////////////////////////////////////////////////////////////
//*******************************************************************
int PWM_MAX = 1000;
int PWM_MIN = -1000; 
/*限幅函数*/
 int Limit(float PWM_INPUT)
{
	if(PWM_INPUT>PWM_MAX)PWM_INPUT=PWM_MAX;
	else if(PWM_INPUT<PWM_MIN)PWM_INPUT=PWM_MIN;
	return PWM_INPUT;
}
/*绝对值函数*/
int GFP_abs(int p)
{
	if(p > 0) return p;
	else return -p;
}
//*********************************************************************

/*赋值函数*/
/*入口参数：PID运算完成后的最终PWM值*/
void Load1(int moto1)
{
	//1.研究正负号，9对应正反转
	if(moto1>0)
	{
		Ain1=1;
		Ain2=0;//正转   
		TIM8->CCR1 = moto1;
	}
	else 		
	{
		Ain1=0;
		Ain2=1;//反转
		TIM8->CCR1 = -1*moto1;
	}
	
}
///////////////////////////////////////////////////////////
void Load2(int moto2)
{
	//1.研究正负号，9对应正反转
	if(moto2>0)
	{
		Bin1=1;
		Bin2=0;//正转 
		TIM8->CCR2 = moto2;
	}
	else 		
	{
		Bin1=0;
		Bin2=1;//反转
		TIM8->CCR2 = -1*moto2;
	}
	
}
/////////////////////////////////////////////////////////////////////
void Load3(int moto3)
{
	//1.研究正负号，9对应正反转
	if(moto3>0)
	{
		Cin1=1;
		Cin2=0;//正转 
		TIM8->CCR3 = moto3;
	}
	else 		
	{
		Cin1=0;
    Cin2=1;//反转
		TIM8->CCR3 = -1*moto3;
	}
	
}
