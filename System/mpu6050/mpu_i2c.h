#ifndef __MPU_I2C_H
#define __MPU_I2C_H


#define  I2C_WR	     0
#define  I2C_RD	     1

//MPU IIC�˿ڶ���
#define  MPU_GPIO_CLK           RCC_APB2Periph_GPIOB
#define  MPU_SCL_GPIO_PORT      GPIOB
#define  MPU_SCL_GPIO_PIN       GPIO_Pin_8
#define  MPU_SDA_GPIO_PORT      GPIOB
#define  MPU_SDA_GPIO_PIN       GPIO_Pin_9
#define  MPU_SDA_PIN_NUMBER     9  //GPIO_Pin_8

//IO �����������
#if 0 /* �������� 1  MPU_IIC_SDA_PIN �Ͱ�λ GPIO_Pin_0~7   */
#define  MPU_SDA_PIN_CRLH_SET     (4*(MPU_SDA_PIN_NUMBER-0))
#define  MPU_SDA_PIN_CRLH_RES     (0XFFFFFFFF-(0XF<<MPU_SDA_PIN_CRLH_SET))
#define  MPU_SDA_IN()  {MPU_SDA_GPIO_PORT->CRL&=MPU_SDA_PIN_CRLH_RES;MPU_SDA_GPIO_PORT->CRL|=8<<MPU_SDA_PIN_CRLH_SET;}
#define  MPU_SDA_OUT() {MPU_SDA_GPIO_PORT->CRL&=MPU_SDA_PIN_CRLH_RES;MPU_SDA_GPIO_PORT->CRL|=3<<MPU_SDA_PIN_CRLH_SET;}
#else /* �������� 0  MPU_IIC_SDA_PIN �߰�λ GPIO_Pin_8~15  */
#define  MPU_SDA_PIN_CRLH_SET     (4*(MPU_SDA_PIN_NUMBER-8))
#define  MPU_SDA_PIN_CRLH_RES     (0XFFFFFFFF-(0XF<<MPU_SDA_PIN_CRLH_SET))
#define  MPU_SDA_IN()  {MPU_SDA_GPIO_PORT->CRH&=MPU_SDA_PIN_CRLH_RES;MPU_SDA_GPIO_PORT->CRH|=8<<MPU_SDA_PIN_CRLH_SET;}
#define  MPU_SDA_OUT() {MPU_SDA_GPIO_PORT->CRH&=MPU_SDA_PIN_CRLH_RES;MPU_SDA_GPIO_PORT->CRH|=3<<MPU_SDA_PIN_CRLH_SET;}
#endif

#define  MPU_IIC_SCL(a)  if(a) GPIO_SetBits(MPU_SCL_GPIO_PORT, MPU_SCL_GPIO_PIN);\
                         else  GPIO_ResetBits(MPU_SCL_GPIO_PORT, MPU_SCL_GPIO_PIN)	
#define  MPU_IIC_SDA(a)  if(a) GPIO_SetBits(MPU_SDA_GPIO_PORT, MPU_SDA_GPIO_PIN);\
                         else  GPIO_ResetBits(MPU_SDA_GPIO_PORT, MPU_SDA_GPIO_PIN)
#define  MPU_IIC_SDA_READ()  GPIO_ReadInputDataBit(MPU_SDA_GPIO_PORT, MPU_SDA_GPIO_PIN)


void MPU_Config(void);
void MPU_IIC_Start(void);
void MPU_IIC_Stop(void);
void MPU_IIC_Ack(void);
void MPU_IIC_NAck(void);
void MPU_IIC_SendByte(u8 _ucByte);
u8 MPU_IIC_ReadByte(u8 ack);
u8 MPU_IIC_WaitAck(void);

u8 MPU_Write_Byte(u8 reg,u8 data);
u8 MPU_Read_Byte(u8 reg);
u8 MPU_Write_Len(u8 addr, u8 reg, u8 len, u8 *buf);
u8 MPU_Read_Len(u8 addr, u8 reg, u8 len, u8 *buf);


#endif  //__MPU_I2C_H
