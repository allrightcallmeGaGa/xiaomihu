#include "car.h"
#include <intrins.h>
#include <STC89C5xRC.H>
#include "motor.h"
sbit D1 = P1^4;
sbit D2 = P1^5;
sbit D3 = P1^6;
sbit D4 = P1^7;
sbit D5 = P1^3;
sbit D6 = P1^2;

void xunji ()         
{
	int s=20,w=30;
        if(D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0){  //全检测到非黑线
          speed_L(s);
					speed_R(s);
					car_go();
        }
				if(D6==1&&D1==1&&D2==1&&D3==1&&D4==1&&D5==1){  //全检测到非黑线
          speed_L(s);
					speed_R(s);
					car_go();}
        if((D6==0&&D1==1&&D2==1&&D3==0&&D4==0&&D5==0)||(D6==0&&D1==0&&D2==1&&D3==0&&D4==0&&D5==0)
					||(D6==0&&D1==1&&D2==0&&D3==0&&D4==0&&D5==0)){  //中间右侧检测到黑线，小车偏左，小车向右移动
          speed_L(w);
					car_rightgo();
					if(D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0){  
            speed_L(s);
						speed_R(s);
						car_go();
					}
				}

        if((D6==0&&D1==0&&D2==0&&D3==1&&D4==1&&D5==0)||(D6==0&&D1==0&&D2==0&&D3==1&&D4==0&&D5==0)
					||(D6==0&&D1==0&&D2==0&&D3==0&&D4==1&&D5==0)){  //中间左侧检测到黑线，小车偏右，小车向左移动
						speed_R(w);
						car_leftgo();
					if(D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0){  
						speed_L(s);
						speed_R(s);
						car_go();
					}
        }
				
					if((D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==1)||(D6==0&&D1==0&&D2==0&&D3==0&&D4==1&&D5==1))  //锐角左拐
				{
						speed_L(40);
						speed_R(40);
						car_leftstop();
					if(D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0){  
						speed_L(s);
						speed_R(s);
						car_go();
					}
				}
				if((D6==1&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0)||(D6==1&&D1==1&&D2==0&&D3==0&&D4==0&&D5==0))	//锐角右拐
				{
						speed_L(40);
						speed_R(40);
						car_rightstop();
					if(D6==0&&D1==0&&D2==0&&D3==0&&D4==0&&D5==0){  
						speed_L(s);
						speed_R(s);
						car_go();
					}
				}
				if(D6==0&&D1==0&&D2==1&&D3==1&&D4==0&&D5==0)
				{
					if(D1==1)
					{
						speed_L(w);
						speed_R(w);
						car_rightstop();
					}
				}
				if(D6==0&&D1==0&&D2==1&&D3==1&&D4==0&&D5==0)
				{
					if(D4==1)
					{
						speed_L(w);
						speed_R(w);
						car_leftstop();
					}
				}
}
