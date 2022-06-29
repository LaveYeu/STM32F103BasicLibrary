#ifndef __OLED_H
#define __OLED_H

#include "headfile.h"


#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64

#define OLED_CMD     0	      //д����
#define OLED_DATA    1	      //д����

//OLED IIC�˿ڶ���
#define  OLED_GPIO_CLK           RCC_APB2Periph_GPIOB
#define  OLED_SCL_GPIO_PORT      GPIOB
#define  OLED_SCL_GPIO_PIN       GPIO_Pin_1
#define  OLED_SDA_GPIO_PORT      GPIOB
#define  OLED_SDA_GPIO_PIN       GPIO_Pin_0

#define OLED_IIC_SCL(a)     if(a) GPIO_SetBits(OLED_SCL_GPIO_PORT,OLED_SCL_GPIO_PIN);\
                            else  GPIO_ResetBits(OLED_SCL_GPIO_PORT,OLED_SCL_GPIO_PIN)

#define OLED_IIC_SDA(a)     if(a) GPIO_SetBits(OLED_SDA_GPIO_PORT,OLED_SDA_GPIO_PIN);\
                            else  GPIO_ResetBits(OLED_SDA_GPIO_PORT,OLED_SDA_GPIO_PIN)



//��������
void OLED_Set_Pos(unsigned char x, unsigned char y);
//����OLED��ʾ    
void OLED_Display_On(void);
//�ر�OLED��ʾ     
void OLED_Display_Off(void);
//��������,������,������Ļ�Ǻ�ɫ��!
void OLED_Clear(void);
//������ʾ
void OLED_On(void);
//OLED��ʼ��
void OLED_Init(void);
//��ָ��λ����ʾһ���ַ�
void OLED_Show_Char(u8 x, u8 y, u8 chr, u8 size);
//��ָ��λ����ʾһ���ַ���
void OLED_Show_String(u8 x, u8 y, u8 *chr, u8 size);
//��ָ��λ����ʾ��λ����(�з���)
void OLED_Show_Int(u8 x, u8 y, int32_t num, u8 len, u8 size);
//��ָ��λ����ʾ��λ����(�޷���)
void OLED_Show_Uint(u8 x, u8 y, u32 num, u8 len, u8 size);
//��ָ��λ����ʾ��λ������
void OLED_Show_Float(u8 x, u8 y, double num, u8 len1, u8 len2, u8 size);



#endif  
	 



