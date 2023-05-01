#include <STC89C5xRC.H>
#include "car.h"
#include "xunji.h"
#include "control.h"
#include "string.h"
#include "speed.h"

unsigned char m;
unsigned int isxunji,iscontrol,isspeed;
//sbit dududu = P2^0;

void receive(m)  //ִ�к���
{
//	dududu = 0;
	PWM_1(1);
	switch(m)
	{
		case 0x01://ǰ��
		car_go();
		break;
		
		case 0x02://��ǰ��ת
		car_leftgo();
		break;
		
		case 0x03://��ǰ��ת
		car_rightgo();
		break;
		
		case 0x04://����
		car_back();
		break;
		
		case 0x05://�����ת
		car_leftback();
		break;
		
		case 0x06://�����ת
		car_rightback();
		break;
		
		case 0x07://ֹͣ
		car_stop();
		break;
		
		case 0x08://ԭ����ת
		car_leftstop();
		break;
		
		case 0x09://ԭ����ת
		car_rightstop();
		break;
		
		case 0x0A://ѭ��
		car_stop();
		isxunji = 1;
		break;
		
		case 0x0B://����ѭ��
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
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xFD;		//���ö�ʱ��ʼֵ
	TH1 = 0xFD;		//���ö�ʱ����ֵ
	ET1 = 0;		//��ֹ��ʱ��%d�ж�
	TR1 = 1;		//��ʱ��1��ʼ��ʱ
	EA = 1;
	ES = 1;      //�����ж�����
	PS = 1;
}

void Uart_Routine() interrupt 4  //�жϺ���
{
	car_stop();
	RI = 0;                      //��������жϱ�־λ
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