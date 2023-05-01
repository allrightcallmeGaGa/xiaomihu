#include <STC89C5xRC.H>
#include "motor.h"

sbit EN1 = P0^7;
sbit EN2 = P0^2;

typedef unsigned int uint;
unsigned char counter,speed;

//定时器+中断
    
void Timer0_Init()		//100微秒@12.000MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
 	ET0 = 1;  //定时器0中断允许开关
	EA = 1;  //定时器总开关
	PT0 = 1;  //定时器0中断优先级
}



void Timer0_Routinr() interrupt 1 //中断函数
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	
	counter++;
	if(counter >= 100)
	{
		counter = 0;
	}
}

void speed_L(uint L){
	if(counter < L)
		EN1 = 1;
	else
		EN1 = 0;
}

void speed_R(uint R)
{
	if(counter < R)
		EN2 = 1;
	else
		EN2 = 0;
}



void PWM_1(unsigned int status){
	EN1 = status;
	EN2 = status;
}

void car_go()  //小车向前直行
{
	LF_motor_go();
	RF_motor_go();
}
void car_back() //小车向后直行
{
	LF_motor_back();
	RF_motor_back();
}
void car_stop() //小车停止
{
	LF_motor_stop();
	RF_motor_stop();
}
void car_leftgo()//小车向前左拐
{
	RF_motor_go();
	LF_motor_stop();
}
void car_rightgo()//小车向前右拐
{
	LF_motor_go();
	RF_motor_stop();
}
void car_leftback()//小车向后左拐
{
	RF_motor_back();
	LF_motor_stop();
}
void car_rightback()//小车向后右拐
{
	LF_motor_back();
	RF_motor_stop();
}
void car_leftstop()//小车原地左转
{
	LF_motor_back();
	RF_motor_go();
}
void car_rightstop()//小车原地右转
{
	LF_motor_go();
	RF_motor_back();
}
