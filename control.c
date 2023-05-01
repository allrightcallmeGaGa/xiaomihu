#include <STC89C5xRC.H>
#include "car.h"

sbit s1=P2^4;
sbit s2=P2^5;
sbit s3=P2^6;
sbit s4=P2^7;

void control()
{
	
		if(s1==0)
		{
			car_go();
		}
		else if(s2==0)
		{
			car_back();
		}
		else if(s3==0)
		{
			car_leftgo();   
		}
		else if(s4==0)
		{
			car_rightgo(); 
		}
		else
		{
			car_stop();
		}
}