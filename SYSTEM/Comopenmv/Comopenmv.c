/*
* @owner        Sharkespeara
* @file         Comopenmv.c
* @brief        openmv通信
* @details      
* @par History  见如下说明
*          
*/

#include"stm32f10x.h"

void Optical_Flow_Receive_Prepare(u8 data)
{
    /* 局部静态变量：接收缓存 */
    static u8 RxBuffer[10];
    /* 数据长度 *//* 数据数组下标 */
    static u8  _data_cnt = 0;
    /* 接收状态 */
    static u8 state = 0;
 
    /* 帧头1 */
    if(state==0&&data==TITLE1)
    {
        state=1;
    }
    /* 帧头2 */
    else if(state==1&&data==TITLE2)
    {
        state=2;
        _data_cnt = 0;
    }
    /* 接收数据租 */
    else if(state==2)
    {
        RxBuffer[++_data_cnt]=data;
        if(_data_cnt>=8)
        {
            state = 0;
            Data_Processing(RxBuffer,_data_cnt);
        }
    }
    /* 若有错误重新等待接收帧头 */
    else
        state = 0;
}
 
 
void Data_Processing(u8 *data_buf,u8 num)
{
	int theta_org,rho_org;
    /* 读取偏移角度原始数据  */
    theta_org = (int)(*(data_buf+1)<<0) | (int)(*(data_buf+2)<<8) | (int)(*(data_buf+3)<<16) | (int)(*(data_buf+4)<<24) ;
    theta_err = theta_org;
 
    /* 读取偏移尺寸原始数据 */
    rho_org = (int)(*(data_buf+5)<<0) | (int)(*(data_buf+6)<<8) | (int)(*(data_buf+7)<<16) | (int)(*(data_buf+8)<<24) ;
    rho_err = rho_org;
}