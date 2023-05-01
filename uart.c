#include <STC89C5xRC.H>
#include "car.h"
#include "xunji.h"
#include "control.h"
#include "string.h"
#include "speed.h"

unsigned char m;
unsigned int isxunji,iscontrol,isspeed;
//sbit dududu = P2^0;

void receive(m)  //执行函数
{
//	dududu = 0;
	PWM_1(1);
	switch(m)
	{
		case 0x01://前进
		car_go();
		break;
		
		case 0x02://向前左转
		car_leftgo();
		break;
		
		case 0x03://向前右转
		car_rightgo();
		break;
		
		case 0x04://后退
		car_back();
		break;
		
		case 0x05://向后左转
		car_leftback();
		break;
		
		case 0x06://向后右转
		car_rightback();
		break;
		
		case 0x07://停止
		car_stop();
		break;
		
		case 0x08://原地左转
		car_leftstop();
		break;
		
		case 0x09://原地右转
		car_rightstop();
		break;
		
		case 0x0A://循迹
		car_stop();
		isxunji = 1;
		break;
		
		case 0x0B://跳出循迹
		car_stop();
		isxunji = 0;
		break;
		
		case 0x0C:
		car_stop();
		iscontrol = 1;
		break;
		
		case 0x0D:
		car_stop();
		iscontrol = 0;
		break;
		
		case 0x0E:
		car_stop();
		isspeed = 1;
		break;
		
		case 0x0F:
		car_stop();
		isspeed = 0;
		break;
		
//		case 0x10:
//		dududu = 1;
//		break;
//		
//		case 0x20:
//		dududu = 0;
//		break;
	}
}

void Uart0_Init(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR &= 0xBF;		//定时器时钟12T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFD;		//设置定时初始值
	TH1 = 0xFD;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//定时器1开始计时
	EA = 1;
	ES = 1;      //串口中断允许
	PS = 1;
}

void Uart_Routine() interrupt 4  //中断函数
{
	car_stop();
	RI = 0;                      //清除接受中断标志位
	receive(SBUF);
}

void SendByte(char mydata)
{
	//ES = 0;
	SBUF = mydata;
	while(TI == 0);
	TI = 0;
	//ES = 1;
}
	

void SendString(char *str)
{
	while(*str!='\0')
		{
			SendByte(*str);
			str++;
	  }
}