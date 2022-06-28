#include "SysTickTimer.h"

u8 fac_us;
u16 fac_ms;

//系统滴答定时器初始化
void SysTick_Init(u8 SYSCLK)//参数是系统时钟频率
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//中断源选择，这里选择(SYSCLK)八分频后的时钟通道.
	fac_us=SYSCLK/8;	//fac_us用于存储(定时器计数1us需要计数多少次的次数)这里是9次，也就是每计数一次，花时(1/9)us.				
	fac_ms=(u16)fac_us*1000;//fac_ms用于存储(定时器计数1ms所要计数多少次的次数)，这里也就是计时1ms，需要定时器计数9000次.			   
}


//微妙延时函数
void Tick_us(u32 nus)//单次调用最大延时(0xFFFFFF)us
{											//24位
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us; 					//重装初值---即对LOAD进行赋值，值是多少是由(32位传递值)传递多少微妙决定。  		 
//计时一微秒定时器计数9次，(nus*fac_us)即若定时2us，则nus==2,fac_us==9,定时器计数9次花时1us，所以这里递减18次。
	SysTick->VAL=0x00;        					//清空计数器当前的计数值
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//开启定时器----等号后面就相当于"1"，或等于--有1出1.所以或等于1，结果肯定为1.	  
	do
	{//temp变量保存CTRL状态
		temp=SysTick->CTRL;//(temp&0x01)若ENABLE已打开，那么这里肯定为"真"，原因自己想(ENABLE为CTRL低十六位的最低位)。
	}while((temp&0x01)&&!(temp&(1<<16)));//[!(temp&(1<<16))]若COUNTFLAG已置1(COUNTFLAG为CTRL的高16位的最低位),那么与(左移16位的"1"相与),结果肯定为"1".
//再“非”，结果为"0"，意思就是：只要你(COUNTFLAG)置一，就代表定时器已经计数到"0"，我这块表达式就最终为"0"那么与前面"相与"，结果肯定为零，则退出while循环
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//关闭定时器----等号后面相当于"0"，与等于--有0出0，所以与等于0，结果肯定为0.
	SysTick->VAL =0X00;      					 //清空计数器当前的计数值
}


//毫秒延时函数
void Tick_ms(u16 nms)//单次调用最大延时(1864)ms------------[0xFFFFFF/(9*1000)=1864]
{	 		  	  					//24位
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;				    //时间加载(ms与us只有这里不同)
	SysTick->VAL =0x00;							          //清空计数器
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;	//开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));		  //等待时间到达   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk;	//关闭计数器
	SysTick->VAL =0X00;       					      //清空计数器	  	    
} 



//一般延时
void delay(u16 y)
{
	u8 z;
	for(;y>0;y--)
		for(z=110;z>0;z--);
}

