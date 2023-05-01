#include <STC89C5xRC.H>
#include "motor.h"

sbit EN1 = P0^7;
sbit EN2 = P0^2;

typedef unsigned int uint;
unsigned char counter,speed;

//��ʱ��+�ж�
    
void Timer0_Init()		//100΢��@12.000MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
 	ET0 = 1;  //��ʱ��0�ж�������
	EA = 1;  //��ʱ���ܿ���
	PT0 = 1;  //��ʱ��0�ж����ȼ�
}



void Timer0_Routinr() interrupt 1 //�жϺ���
{
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	
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

void car_go()  //С����ǰֱ��
{
	LF_motor_go();
	RF_motor_go();
}
void car_back() //С�����ֱ��
{
	LF_motor_back();
	RF_motor_back();
}
void car_stop() //С��ֹͣ
{
	LF_motor_stop();
	RF_motor_stop();
}
void car_leftgo()//С����ǰ���
{
	RF_motor_go();
	LF_motor_stop();
}
void car_rightgo()//С����ǰ�ҹ�
{
	LF_motor_go();
	RF_motor_stop();
}
void car_leftback()//С��������
{
	RF_motor_back();
	LF_motor_stop();
}
void car_rightback()//С������ҹ�
{
	LF_motor_back();
	RF_motor_stop();
}
void car_leftstop()//С��ԭ����ת
{
	LF_motor_back();
	RF_motor_go();
}
void car_rightstop()//С��ԭ����ת
{
	LF_motor_go();
	RF_motor_back();
}
