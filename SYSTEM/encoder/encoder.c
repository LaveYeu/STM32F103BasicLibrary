/**
* @owner        Sharkespeara
* @file         encoder.c
* @brief        ��������ʼ������
* @details      
* @par History  ������˵��
*          
*/

#include "encoder.h"



void Encoder_TIM2_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//����ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//��ʼ��GPIO--PA0��PA1
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
		
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);//��ʼ����ʱ����
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInitStruct.TIM_Period=65535; //�趨�������Զ���װֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);//���ñ�����ģʽ
	
	TIM_ICStructInit(&TIM_ICInitStruct);//��ʼ�����벶��
	TIM_ICInitStruct.TIM_ICFilter=10;//�˲���
	TIM_ICInit(TIM2,&TIM_ICInitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ�1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;    //��Ӧ���ȼ�3
	NVIC_Init(&NVIC_InitStruct);
	
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//������������жϱ�־λ//ʹ�ܶ�ʱ���ж�
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);//���TIM�ĸ��±�־λ

	TIM_SetCounter(TIM2,0);//���㶨ʱ������ֵ
	
	TIM_Cmd(TIM2,ENABLE);//������ʱ��
}

void Encoder_TIM3_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ�����ų�ʼ���Ľṹ��  
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//����һ����ʱ����ʼ���Ľṹ��
  TIM_ICInitTypeDef TIM_ICInitStructure; //����һ����ʱ��������ģʽ��ʼ���Ľṹ��
	NVIC_InitTypeDef NVIC_InitStruct;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
 
  GPIO_PinRemapConfig(GPIO_FullRemap_TIM2, ENABLE);
  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_TimeBaseStructure.TIM_Period = 65535; //�趨�������Զ���װֵ
	TIM_TimeBaseStructure.TIM_Prescaler = 0; // Ԥ��Ƶ�� 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //ѡ��ʱ�ӷ�Ƶ������Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3��CH1��CH2ͬʱ�������ķ�Ƶ
	TIM_ICStructInit(&TIM_ICInitStructure); //��TIM_ICInitStruct �е�ÿһ��������ȱʡֵ����
	TIM_ICInitStructure.TIM_ICFilter = 10;  //�����˲�������
	TIM_ICInit(TIM3, &TIM_ICInitStructure);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;   //ʹ���ⲿ�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ�1
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;    //��Ӧ���ȼ�3
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//ʹ�ܶ�ʱ���ж�

	TIM_Cmd(TIM3, ENABLE);
}


void Encoder_TIM4_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_ICInitTypeDef TIM_ICInitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_6 |GPIO_Pin_7;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStruct);
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=65535;
	TIM_TimeBaseInitStruct.TIM_Prescaler=0;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStruct);
	
	TIM_EncoderInterfaceConfig(TIM4,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	
	TIM_ICStructInit(&TIM_ICInitStruct);
	TIM_ICInitStruct.TIM_ICFilter=10;
	TIM_ICInit(TIM4,&TIM_ICInitStruct);
	
	TIM_ClearFlag(TIM4,TIM_FLAG_Update);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	
	TIM_SetCounter(TIM4,0);

	TIM_Cmd(TIM4,ENABLE);
}

/**********************
������
�ٶȶ�ȡ����
��ڲ�������ʱ��
**********************/
int Read_Encoder(u8 TIMX)
{
    int Encoder_TIM;
    switch (TIMX)
    {
    case 2:
        Encoder_TIM = (short)TIM2->CNT;
        TIM2->CNT = 0;
        break;
    case 3:
        Encoder_TIM = (short)TIM3->CNT;
        TIM3->CNT = 0;
        break;
    case 4:
        Encoder_TIM = (short)TIM4->CNT;
        TIM4->CNT = 0;
        break;
    default:
        Encoder_TIM = 0;
    }
    return Encoder_TIM;
}


