#include <STC89C5xRC.H>

 
sbit IN11 = P0^3;//����
sbit IN12 = P0^4;
sbit IN13 = P0^5;//����
sbit IN14 = P0^6;

void RF_motor_go() //����ת
{
    IN11 = 0;
    IN12 = 1;
}
void RF_motor_back()//��ת
{
    IN11 = 1;
    IN12 = 0;
}
void RF_motor_stop()//��ֹͣ
{
	IN11 = 0;
    IN12 = 0;
}
 
void LF_motor_go() //����ת
{
    IN13 = 0;
    IN14 = 1;
}
void LF_motor_back()//�ҵ�ת
{
    IN13 = 1;
    IN14 = 0;
}
void LF_motor_stop()//��ֹͣ
{
		IN13 = 0;
    IN14 = 0;
}
