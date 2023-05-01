#include <STC89C5xRC.H>

#include "uart.h"

unsigned int num_L = 0,num_R = 0;//ͳ�Ƹ�������
unsigned int cnt = 0;
unsigned int rate_L,rate_R;//�ٶ�
unsigned int signal = 0;//���ͱ�־λ
unsigned char rate_LMes[20],rate_RMes[20];//�ַ���������


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

void Timer2Init(void)		//50����@11.0592MHz
{
	T2MOD = 0;		//��ʼ��ģʽ�Ĵ���
	T2CON = 0;		//��ʼ�����ƼĴ���
	TL2 = 0x00;		//���ö�ʱ��ʼֵ
	TH2 = 0x4C;		//���ö�ʱ��ʼֵ
	RCAP2L = 0x00;		//���ö�ʱ����ֵ
	RCAP2H = 0x4C;		//���ö�ʱ����ֵ
	TR2 = 1;		//��ʱ��2��ʼ��ʱ
	ET2 = 1;
	PT2 = 0;
}

 void Timer2Handler() interrupt 5
 {	 
	cnt++;
	TF2 = 0;
	TL2 = 0xB0;		//���ö�ʱ��ʼֵ
	TH2 = 0x3C;		//���ö�ʱ��ʼֵ
	if(cnt ==20)//����20�ξ���1��
	{
		cnt = 0;
		rate_L = num_L;
		rate_R = num_R;
		num_L = 0;  //�����ʼ��
		num_R = 0;
		signal = 1;
	}		
 }