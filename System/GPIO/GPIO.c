/*
* @owner        Sharkespeara
* @file         GPIO.c
* @brief        GPIO�˿ڳ�ʼ��
* @details      
* @par History  ������˵��
*          
*/

#include "GPIO.h"


/*
����ģʽ

    -���븡�գ�GPIO_Mode_IN_FLOATING��

    -��������(GPIO_Mode_IPU)

    -��������(GPIO_Mode_IPD)

    -ģ������(GPIO_Mode_AIN)

���ģʽ

    -��©���(GPIO_Mode_Out_OD)

    -��©���ù���(GPIO_Mode_AF_OD)

    -����ʽ���(GPIO_Mode_Out_PP)

    -����ʽ���ù���(GPIO_Mode_AF_PP)
*/



#ifdef EN_GPIOA
void GPIO_SITEA(void)
{
/*********************************************************************************/
/*******************GPIOA*****************************/
/******************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  //ʹ��GPIOAʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);//��ʼ�� 

//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);   //�ø�
}
#endif

#ifdef EN_GPIOB
void GPIO_SITEB(void)
{
/*********************************************************************************/
	/*******************GPIOB*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  //ʹ��GPIOBʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);//��ʼ�� 

	//	GPIO_ResetBits(GPIOB,GPIO_Pin_0);  //�õ�
    //	GPIO_SetBits(GPIOB,GPIO_Pin_0);   //�ø�
}
#endif

#ifdef EN_GPIOC
void GPIO_SITEC(void)
{
/*********************************************************************************/
/*******************GPIOC*****************************/
/********************************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  //ʹ��GPIOCʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);//��ʼ��

//	GPIO_ResetBits(GPIOC,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOC,GPIO_Pin_0);   //�ø�
}
#endif

#ifdef EN_GPIOD
void GPIO_SITED(void)
{
/*********************************************************************************/
/*******************GPIOD*****************************/
/********************************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  //ʹ��GPIODʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_PIN_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStruct);//��ʼ�� 

	//	GPIO_ResetBits(GPIOD,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOD,GPIO_Pin_0);   //�ø�
}
#endif

#ifdef EN_GPIOE
void GPIO_SITEE(void)
{
/*********************************************************************************/
	/*******************GPIOE*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);  //ʹ��GPIOEʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStruct);//��ʼ�� 

	//	GPIO_ResetBits(GPIOE,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOE,GPIO_Pin_0);   //�ø�
}
#endif

#ifdef EN_GPIOF
void GPIO_SITEF(void)
{
/*********************************************************************************/
	/*******************GPIOF*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);  //ʹ��GPIOFʱ��
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOF,&GPIO_InitStruct);//��ʼ�� 

	//	GPIO_ResetBits(GPIOE,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOE,GPIO_Pin_0);   //�ø�
}
#endif



/*���ú���*/
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //�õ�
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);   //�ø�