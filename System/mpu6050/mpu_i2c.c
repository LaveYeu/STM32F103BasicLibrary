#include "mpu_i2c.h"




static void MPU_IIC_Delay(void)
{
	Delay_us(2);
}

void MPU_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(MPU_GPIO_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = MPU_SCL_GPIO_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(MPU_SCL_GPIO_PORT, &GPIO_InitStructure);
	GPIO_SetBits(MPU_SCL_GPIO_PORT, MPU_SCL_GPIO_PIN);

	GPIO_InitStructure.GPIO_Pin = MPU_SDA_GPIO_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_Init(MPU_SDA_GPIO_PORT, &GPIO_InitStructure);
	GPIO_SetBits(MPU_SDA_GPIO_PORT, MPU_SDA_GPIO_PIN);
}

void MPU_IIC_Start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
	MPU_SDA_OUT();
	MPU_IIC_SDA(1);
	MPU_IIC_SCL(1);
	MPU_IIC_Delay();
	MPU_IIC_SDA(0);
	MPU_IIC_Delay();
	MPU_IIC_SCL(0);
	MPU_IIC_Delay();
}

void MPU_IIC_Stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	MPU_SDA_OUT();
	MPU_IIC_SCL(0);
	MPU_IIC_SDA(0);
	MPU_IIC_Delay();
	MPU_IIC_SCL(1);
	MPU_IIC_SDA(1);
	MPU_IIC_Delay();
}

void MPU_IIC_Ack(void)
{
	MPU_IIC_SCL(0);
	MPU_SDA_OUT();
	MPU_IIC_SDA(0);	/* CPU����SDA = 0 */
	MPU_IIC_Delay();
	MPU_IIC_SCL(1);	/* CPU����1��ʱ�� */
	MPU_IIC_Delay();
	MPU_IIC_SCL(0);
	MPU_IIC_Delay();
}

void MPU_IIC_NAck(void)
{
	MPU_IIC_SCL(0);
	MPU_SDA_OUT();
	MPU_IIC_SDA(1);	/* CPU����SDA = 1 */
	MPU_IIC_Delay();
	MPU_IIC_SCL(1);	/* CPU����1��ʱ�� */
	MPU_IIC_Delay();
	MPU_IIC_SCL(0);
	MPU_IIC_Delay();	
}

void MPU_IIC_SendByte(u8 _ucByte)
{
	u8 i;

	MPU_SDA_OUT();
	MPU_IIC_SCL(0);

	/* �ȷ����ֽڵĸ�λbit7 */
	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			MPU_IIC_SDA(1);
		}
		else
		{
			MPU_IIC_SDA(0);
		}
		MPU_IIC_Delay();
		MPU_IIC_SCL(1);
		MPU_IIC_Delay();	
		MPU_IIC_SCL(0);
		if (i == 7)
		{
			 MPU_IIC_SDA(1); // �ͷ�����
		}
		_ucByte <<= 1;	/* ����һ��bit */
		MPU_IIC_Delay();
	}
}

u8 MPU_IIC_ReadByte(u8 ack)
{
	u8 i;
	u8 value = 0;

	MPU_SDA_IN();

	/* ������1��bitΪ���ݵ�bit7 */
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		MPU_IIC_SCL(0);
		MPU_IIC_Delay();
		MPU_IIC_SCL(1);
		MPU_IIC_Delay();
		if (MPU_IIC_SDA_READ())
		{
			value++;
		}
		MPU_IIC_SCL(0);
		MPU_IIC_Delay();
	}
	if(ack==0)
		MPU_IIC_NAck();
	else
		MPU_IIC_Ack();
	return value;
}

u8 MPU_IIC_WaitAck(void)
{
	u8 re;

	MPU_SDA_IN();

	MPU_IIC_SDA(1);	/* CPU�ͷ�SDA���� */
	MPU_IIC_Delay();
	MPU_IIC_SCL(1);	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
	MPU_IIC_Delay();
	if (MPU_IIC_SDA_READ())	/* CPU��ȡSDA����״̬ */
	{
		re = 1;
	}
	else
	{
		re = 0;
	}
	MPU_IIC_SCL(0);
	MPU_IIC_Delay();
	return re;
}


//IICдһ���ֽ� 
//reg:�Ĵ�����ַ data:���� ����ֵ:0,���� ����,����
u8 MPU_Write_Byte(u8 reg,u8 data) 				 
{ 
    MPU_IIC_Start(); 
	MPU_IIC_SendByte((MPU_ADDR<<1)|0);//����������ַ+д����	
	if(MPU_IIC_WaitAck())	//�ȴ�Ӧ��
	{
		MPU_IIC_Stop();		 
		return 1;		
	}
    MPU_IIC_SendByte(reg);	//д�Ĵ�����ַ
    MPU_IIC_WaitAck();		//�ȴ�Ӧ�� 
	MPU_IIC_SendByte(data);//��������
	if(MPU_IIC_WaitAck())	//�ȴ�ACK
	{
		MPU_IIC_Stop();	 
		return 1;		 
	}		 
    MPU_IIC_Stop();	 
	return 0;
}
//IIC��һ���ֽ� 
//reg:�Ĵ�����ַ ����ֵ:����������
u8 MPU_Read_Byte(u8 reg)
{
	u8 res;
    MPU_IIC_Start(); 
	MPU_IIC_SendByte((MPU_ADDR<<1)|0);//����������ַ+д����	
	MPU_IIC_WaitAck();		//�ȴ�Ӧ�� 
    MPU_IIC_SendByte(reg);	//д�Ĵ�����ַ
    MPU_IIC_WaitAck();		//�ȴ�Ӧ��
    MPU_IIC_Start();
	MPU_IIC_SendByte((MPU_ADDR<<1)|1);//����������ַ+������	
    MPU_IIC_WaitAck();		//�ȴ�Ӧ�� 
	res=MPU_IIC_ReadByte(0);//��ȡ����,����nACK 
    MPU_IIC_Stop();			//����һ��ֹͣ���� 
	return res;		
}
//IIC����д
//addr:������ַ reg:�Ĵ�����ַ len:д�볤�� buf:������ ����ֵ:0,���� ����,����
u8 MPU_Write_Len(u8 addr, u8 reg, u8 len, u8 *buf)
{
	u8 i; 
    MPU_IIC_Start(); 
	MPU_IIC_SendByte((addr<<1)|0);//����������ַ+д����	
	if(MPU_IIC_WaitAck())	//�ȴ�Ӧ��
	{
		MPU_IIC_Stop();		 
		return 1;		
	}
    MPU_IIC_SendByte(reg);	//д�Ĵ�����ַ
    MPU_IIC_WaitAck();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		MPU_IIC_SendByte(buf[i]);	//��������
		if(MPU_IIC_WaitAck())		//�ȴ�ACK
		{
			MPU_IIC_Stop();	 
			return 1;		 
		}		
	}    
    MPU_IIC_Stop();	 
	return 0;	
} 
//IIC������
//addr:������ַ reg:�Ĵ�����ַ len:��ȡ���� buf:������ ����ֵ:0,���� ����,����
u8 MPU_Read_Len(u8 addr, u8 reg, u8 len, u8 *buf)
{ 
 	MPU_IIC_Start(); 
	MPU_IIC_SendByte((addr<<1)|0);//����������ַ+д����	
	if(MPU_IIC_WaitAck())	//�ȴ�Ӧ��
	{
		MPU_IIC_Stop();		 
		return 1;		
	}
    MPU_IIC_SendByte(reg);	//д�Ĵ�����ַ
    MPU_IIC_WaitAck();		//�ȴ�Ӧ��
    MPU_IIC_Start();
	MPU_IIC_SendByte((addr<<1)|1);//����������ַ+������	
    MPU_IIC_WaitAck();		//�ȴ�Ӧ�� 
	while(len)
	{
		if(len==1)
		*buf=MPU_IIC_ReadByte(0);   //������,����nACK 
		else 
		*buf=MPU_IIC_ReadByte(1);   //������,����ACK  
		len--;
		buf++; 
	}    
    MPU_IIC_Stop();	//����һ��ֹͣ���� 
	return 0;	
}






