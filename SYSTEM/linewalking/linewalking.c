/**
* @owner        Sharkespeara
* @file         linewalking.c
* @brief        Ѳ��ģʽ�˶�����
* @details      
* @par History  ������˵��
*          
*/


#include "linewalking.h"
#include "sys.h"
#include "motor.h"
#include "delay.h"
#include "stdlib.h"


void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2)
{
	*p_iL1 = GPIO_ReadInputDataBit(LineWalk_L1_PORT, LineWalk_L1_PIN);
	*p_iL2 = GPIO_ReadInputDataBit(LineWalk_L2_PORT, LineWalk_L2_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(LineWalk_R1_PORT, LineWalk_R1_PIN);
	*p_iR2 = GPIO_ReadInputDataBit(LineWalk_R2_PORT, LineWalk_R2_PIN);		
}


void LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	//��ȡ���߼��״̬	

	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW) //�����
    {
      	Car_SpinLeft(7000, 7000);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW)) //�Ҵ���
	{ 
      	Car_SpinRight(7000, 7000);
		delay_ms(80);
    }  
    else if( LineL1 == LOW ) //���������
    {  
		Car_SpinLeft(6800, 6800);
		delay_ms(10);
	}
    else if ( LineR2 == LOW) //���������
    {  
		Car_SpinRight(6800, 6800);
		delay_ms(10);
	}
    else if (LineL2 == LOW && LineR1 == HIGH) //�м�����ϵĴ�����΢������ת
    {   
		Car_Left(6500);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW) //�м�����ϵĴ�����΢������ת
    {   
		Car_Right(6500);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // ���Ǻ�ɫ, ����ǰ��
    {  
		Car_Run(7200);
	}	
}
