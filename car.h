#ifndef _motor_h_
#define _motor_h_
#include <STC89C5xRC.H>

void Timer0_Init();
void speed_L(int L);
void speed_R(int R);
void PWM_1(unsigned int status);
void car_go();       //小车向前直行
void car_back();     //小车向后直行
void car_stop();     //小车停止
void car_leftgo();   //小车向前左拐
void car_rightgo();  //小车向前右拐
void car_leftback(); //小车向后左拐
void car_rightback();//小车向后右拐
void car_leftstop(); //小车原地左拐
void car_rightstop();//小车原地右拐

#endif