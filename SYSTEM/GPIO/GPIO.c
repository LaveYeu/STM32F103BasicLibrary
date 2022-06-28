/*
* @owner        Sharkespeara
* @file         GPIO.c
* @brief        GPIO端口初始化
* @details      
* @par History  见如下说明
*          
*/

#include "GPIO.h"


/*
输入模式

    -输入浮空（GPIO_Mode_IN_FLOATING）

    -输入上拉(GPIO_Mode_IPU)

    -输入下拉(GPIO_Mode_IPD)

    -模拟输入(GPIO_Mode_AIN)

输出模式

    -开漏输出(GPIO_Mode_Out_OD)

    -开漏复用功能(GPIO_Mode_AF_OD)

    -推挽式输出(GPIO_Mode_Out_PP)

    -推挽式复用功能(GPIO_Mode_AF_PP)
*/



#ifdef EN_GPIOA
void GPIO_SITEA(void)
{
/*********************************************************************************/
/*******************GPIOA*****************************/
/******************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);  //使能GPIOA时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);//初始化 

//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);   //置高
}
#endif

#ifdef EN_GPIOB
void GPIO_SITEB(void)
{
/*********************************************************************************/
	/*******************GPIOB*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);  //使能GPIOB时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);//初始化 

	//	GPIO_ResetBits(GPIOB,GPIO_Pin_0);  //置低
    //	GPIO_SetBits(GPIOB,GPIO_Pin_0);   //置高
}
#endif

#ifdef EN_GPIOC
void GPIO_SITEC(void)
{
/*********************************************************************************/
/*******************GPIOC*****************************/
/********************************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);  //使能GPIOC时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStruct);//初始化

//	GPIO_ResetBits(GPIOC,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOC,GPIO_Pin_0);   //置高
}
#endif

#ifdef EN_GPIOD
void GPIO_SITED(void)
{
/*********************************************************************************/
/*******************GPIOD*****************************/
/********************************************************************************/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);  //使能GPIOD时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_PIN_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStruct);//初始化 

	//	GPIO_ResetBits(GPIOD,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOD,GPIO_Pin_0);   //置高
}
#endif

#ifdef EN_GPIOE
void GPIO_SITEE(void)
{
/*********************************************************************************/
	/*******************GPIOE*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);  //使能GPIOE时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStruct);//初始化 

	//	GPIO_ResetBits(GPIOE,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOE,GPIO_Pin_0);   //置高
}
#endif

#ifdef EN_GPIOF
void GPIO_SITEF(void)
{
/*********************************************************************************/
	/*******************GPIOF*****************************/
/********************************************************************************/
    GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);  //使能GPIOF时钟
	                   
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOF,&GPIO_InitStruct);//初始化 

	//	GPIO_ResetBits(GPIOE,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOE,GPIO_Pin_0);   //置高
}
#endif



/*常用函数*/
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);  //置低
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);   //置高