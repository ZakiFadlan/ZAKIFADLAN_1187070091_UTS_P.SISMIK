#include<reg51.h> 

sbit mot_pin1 = P1^1;
sbit mot_pin2 = P1^2;
sbit sensor = P2^0;
sbit led1 = P1^3;
sbit led2 = P1^4;
sbit led3 = P1^5;

void Delay1(int);
int Delay2(int);


void main (void)
{
sensor = 1;
mot_pin1 = 0;
mot_pin2 = 1;
Delay1(2000);
mot_pin1 = 0;
mot_pin2 = 0;
led1 = 0;
led2 = 0;
led3 = 0;
	
		
while(1) 
{
if(sensor == 0 )
{
label1:
mot_pin1 = 1;								
mot_pin2 = 0;
led1=1;led2=0;led3=0;			
					
Delay1(6000);
						
label2:
mot_pin1 = 0; 
mot_pin2 = 0;
led1=0;led2=1;led3=0;
						
Delay2(2000);
						
if(Delay2() == 1)	
{
goto label2;
}
						
mot_pin1 = 0; 							
mot_pin2 = 1;
led1=0;led2=0;led3=1;
						
Delay2(3000);
						
if(Delay2() == 1)
{
goto label1;
}
						
mot_pin1 = 0;								
mot_pin2 = 0;
led1=0;led2=0;led3=0;
}
}
}

void Delay1(int k)
{
  int j;
  int i;
  for(i=0;i<k;i++)
{
for(j=0;j<100;j++){}
}
}

int Delay2(int k)
{
  int j;
  int i;
  for(i=0;i<k;i++)
{
for(j=0;j<100;j++)
{
if(sensor == 0)
{
mot_pin1 = 0;
mot_pin2 = 0;
return 1;
}
}
}
}