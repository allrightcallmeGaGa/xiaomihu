#include <STC89C5xRC.H>

#include "uart.h"

unsigned int num_L = 0,num_R = 0;//统计格子数量
unsigned int cnt = 0;
unsigned int rate_L,rate_R;//速度
unsigned int signal = 0;//发送标志位
unsigned char rate_LMes[20],rate_RMes[20];//字符串缓冲区


void EX_Init()
{
	EX1=1;
	EX0=1;
	IT1=1;
	IT0=1;
}

void rate_LHandler() interrupt 0
{
	num_L++;
}

void rate_RHandler() interrupt 2
{
	num_R++;
}

void Timer2Init(void)		//50毫秒@11.0592MHz
{
	T2MOD = 0;		//初始化模式寄存器
	T2CON = 0;		//初始化控制寄存器
	TL2 = 0x00;		//设置定时初始值
	TH2 = 0x4C;		//设置定时初始值
	RCAP2L = 0x00;		//设置定时重载值
	RCAP2H = 0x4C;		//设置定时重载值
	TR2 = 1;		//定时器2开始计时
	ET2 = 1;
	PT2 = 0;
}

 void Timer2Handler() interrupt 5
 {	 
	cnt++;
	TF2 = 0;
	TL2 = 0xB0;		//设置定时初始值
	TH2 = 0x3C;		//设置定时初始值
	if(cnt ==20)//爆表20次经过1秒
	{
		cnt = 0;
		rate_L = num_L;
		rate_R = num_R;
		num_L = 0;  //清零初始化
		num_R = 0;
		signal = 1;
	}		
 }