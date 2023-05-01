#ifndef _motor_h_
#define _motor_h_
#include <STC89C5xRC.H>

void Timer0_Init();
void speed_L(int L);
void speed_R(int R);
void PWM_1(unsigned int status);
void car_go();       //С����ǰֱ��
void car_back();     //С�����ֱ��
void car_stop();     //С��ֹͣ
void car_leftgo();   //С����ǰ���
void car_rightgo();  //С����ǰ�ҹ�
void car_leftback(); //С��������
void car_rightback();//С������ҹ�
void car_leftstop(); //С��ԭ�����
void car_rightstop();//С��ԭ���ҹ�

#endif