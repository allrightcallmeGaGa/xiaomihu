#include <STC89C5xRC.H>
#include <stdio.h>
#include "car.h"
#include "xunji.h"
#include "uart.h"
#include "motor.h"
#include "control.h"
#include "speed.h"

extern unsigned int isxunji,iscontrol,isspeed;
extern unsigned int num_L,num_R;//统计格子数量
extern unsigned int cnt;
extern unsigned int rate_L,rate_R;//速度
extern unsigned int signal;//发送标志位
extern unsigned char rate_LMes[20],rate_RMes[20];//字符串缓冲区

void main()
{
	car_stop();
	Timer0_Init();
	Uart0_Init();
	Timer2Init();
	while (1)
	{
		if(isxunji == 1)
		{
			xunji();
		}
		 if(iscontrol == 1)
		{
			control();
		}
		 if(isspeed == 1){
			 EX_Init();
			if(signal==1)
			{
				signal=0;
				sprintf(rate_LMes, "\nL:%d cm/s",rate_L);//字符组装
				SendString(rate_LMes);
				sprintf(rate_RMes, "\nR:%d cm/s",rate_R);
				SendString(rate_RMes);//字符发送
			}
		}

	}
}
