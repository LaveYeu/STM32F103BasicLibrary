/**
* @owner        Sharkespeara
* @file         pwm.c
* @brief        PWM����
* @details      
* @par History  ������˵��
*          
*/

#include "stm32f10x.h"
#include "PWM.h"
#include <stdlib.h>
#include <string.h>

#ifdef EN_TIM1
/**************************TIM1**********************************************************/
void TIM1_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{

	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	
 
   //���ø�����Ϊ�����������,���PWM���岨��	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11; //TIM_CH1,CH2,CH3,CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
 
   //��ʼ��TIM1
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	//��ʼ��TIM1 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	//TIM_OCInitStructure.TIM_Pulse=0;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 OC2
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM1��CCR2�ϵ�Ԥװ�ؼĴ���

	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 OC2
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM1��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 OC2
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM1��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 OC2
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM1��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);   //�߼���ʱ��ר��
	
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM1
#endif




#ifdef EN_TIM2
/**************************TIM2**********************************************************/
/* ����TIM5ͬʱʹ�ã��޶�STM32F103RCTX����ͨ����Ϊ
   CH1--- PA15
   CH2--- PB3
   CH3--- PB10
   CH4--- PB11*/
void TIM2_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{

	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;//����ṹ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;//�����ʼ���ṹ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��2ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3; //TIM_CH1 TIM_CH2 TIM_CH3 TIM_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ������


	//��ʼ��TIM2
	TIM_TimeBaseInitStruct.TIM_Period = arr;//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;//ʱ�ӷָ�
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);//�������Ϲ��ܶԶ�ʱ�����г�ʼ��

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//����Ƚϼ��Ե�

	TIM_OC1Init(TIM2, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM2��CCR2�ϵ�Ԥװ��ֵ

	TIM_Cmd(TIM2, ENABLE);//ʹ�ܶ�ʱ��TIM2
}
#endif




#ifdef EN_TIM3
/**************************TIM3**********************************************************/
void TIM3_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{

	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;//����ṹ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;//�����ʼ���ṹ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//ʹ�ܶ�ʱ��3ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //TIM_CH1 TIM_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ������
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO , ENABLE );
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//TIM_CH3 TIM_CH4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

	//��ʼ��TIM3
	TIM_TimeBaseInitStruct.TIM_Period = arr;//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;//ʱ�ӷָ�
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStruct);//�������Ϲ��ܶԶ�ʱ�����г�ʼ��

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//����Ƚϼ��Ե�

	TIM_OC1Init(TIM3, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM3��CCR1�ϵ�Ԥװ��ֵ
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM3��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM3��CCR3�ϵ�Ԥװ��ֵ
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM3��CCR4�ϵ�Ԥװ��ֵ

	TIM_Cmd(TIM3, ENABLE);//ʹ�ܶ�ʱ��TIM3
}
#endif




#ifdef EN_TIM4
/**************************TIM4**********************************************************/
void TIM4_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{

	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;//����ṹ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;//�����ʼ���ṹ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//ʹ�ܶ�ʱ��3ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7| GPIO_Pin_8| GPIO_Pin_9; //TIM_CH1 TIM_CH2 TIM_CH3 TIM_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ������
	

	//��ʼ��TIM4
	TIM_TimeBaseInitStruct.TIM_Period = arr;//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;//ʱ�ӷָ�
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStruct);//�������Ϲ��ܶԶ�ʱ�����г�ʼ��

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//����Ƚϼ��Ե�

	TIM_OC1Init(TIM4, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM4��CCR1�ϵ�Ԥװ��ֵ
	
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM4��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM4��CCR3�ϵ�Ԥװ��ֵ
	
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM4��CCR4�ϵ�Ԥװ��ֵ

	TIM_Cmd(TIM4, ENABLE);//ʹ�ܶ�ʱ��TIM4
}
#endif



#ifdef EN_TIM5
/**************************TIM5**********************************************************/
/*��TIM2ͬʱʹ��ʱ������STM32F103RCTX��ͨ���ڷ����仯�����TIM2ע��*/
void TIM5_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{

	GPIO_InitTypeDef GPIO_InitStructure;//����ṹ��
	TIM_OCInitTypeDef TIM_OCInitStructure;//����ṹ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseInitStruct;//�����ʼ���ṹ��

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);//ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);//ʹ�ܶ�ʱ��5ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3; //TIM_CH1 TIM_CH2 TIM_CH3 TIM_CH4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�������칦��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ������


	//��ʼ��TIM5
	TIM_TimeBaseInitStruct.TIM_Period = arr;//�Զ���װ�ؼĴ�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;//TIMXԤ��Ƶ��ֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	TIM_TimeBaseInitStruct.TIM_ClockDivision = 0;//ʱ�ӷָ�
	TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStruct);//�������Ϲ��ܶԶ�ʱ�����г�ʼ��

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//ѡ��ʱ��ģʽ��TIM�����ȵ���ģʽ1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//����Ƚϼ��Ե�

	TIM_OC1Init(TIM5, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC1PreloadConfig(TIM5, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM5��CCR1�ϵ�Ԥװ��ֵ
	
	TIM_OC2Init(TIM5, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC2PreloadConfig(TIM5, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM5��CCR2�ϵ�Ԥװ��ֵ
	
	TIM_OC3Init(TIM5, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC3PreloadConfig(TIM5, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM5��CCR3�ϵ�Ԥװ��ֵ
	
	TIM_OC4Init(TIM5, &TIM_OCInitStructure);//���ݽṹ����Ϣ���г�ʼ��
	TIM_OC4PreloadConfig(TIM5, TIM_OCPreload_Enable);//ʹ�ܶ�ʱ��TIM5��CCR4�ϵ�Ԥװ��ֵ

	TIM_Cmd(TIM5, ENABLE);//ʹ�ܶ�ʱ��TIM5
}
#endif




#ifdef EN_TIM8
/**************************TIM8**********************************************************/
void TIM8_PWM_Init(u16 arr,u16 psc)//arr �Զ���װ�ؼĴ�����ֵ  psc TIMXԤ��Ƶ��ֵ
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	
 
   //���ø�����Ϊ�����������,���TIM8 CH2��PWM���岨��	GPIOB.5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8; //TIM_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIO
 
   //��ʼ��TIM8
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	//��ʼ��TIM8 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	//TIM_OCInitStructure.TIM_Pulse=0;

	TIM_OC1Init(TIM8, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM8 OC1
	TIM_OC1PreloadConfig(TIM8, TIM_OCPreload_Enable);  //ʹ��TIM8��CCR1�ϵ�Ԥװ�ؼĴ���

	TIM_OC2Init(TIM8, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM8 OC2
	TIM_OC2PreloadConfig(TIM8, TIM_OCPreload_Enable);  //ʹ��TIM8��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC3Init(TIM8, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM8 OC3
	TIM_OC3PreloadConfig(TIM8, TIM_OCPreload_Enable);  //ʹ��TIM8��CCR3�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC4Init(TIM8, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM8 OC4
	TIM_OC4PreloadConfig(TIM8, TIM_OCPreload_Enable);  //ʹ��TIM8��CCR4�ϵ�Ԥװ�ؼĴ���
	
	TIM_CtrlPWMOutputs(TIM8,ENABLE);  //�߼���ʱ��ר��
	
	TIM_Cmd(TIM8, ENABLE);  //ʹ��TIM8
}
#endif