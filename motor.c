#include <STC89C5xRC.H>

 
sbit IN11 = P0^3;//左轮
sbit IN12 = P0^4;
sbit IN13 = P0^5;//右轮
sbit IN14 = P0^6;

void RF_motor_go() //左正转
{
    IN11 = 0;
    IN12 = 1;
}
void RF_motor_back()//左倒转
{
    IN11 = 1;
    IN12 = 0;
}
void RF_motor_stop()//左停止
{
	IN11 = 0;
    IN12 = 0;
}
 
void LF_motor_go() //右正转
{
    IN13 = 0;
    IN14 = 1;
}
void LF_motor_back()//右倒转
{
    IN13 = 1;
    IN14 = 0;
}
void LF_motor_stop()//右停止
{
		IN13 = 0;
    IN14 = 0;
}
