#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;


#define led P0//后面不用加分号

void delay(u16 i)
{
	while(i--);
}

void main()
{
	u8 i;
	led=0*01;
	 delay(50000);		
	while(i--)
	{
       for(i=0;i<8;i++){
				 led=(0*01<<i);//   0000 0001    0000 0010     0000 0100灯亮一直流水流动
				 delay(50000);
       }
			//	 for(i=0;i<7;i++){
			//	led=_cror_(led,1);
			//	delay(50000);
			//	 }					 
			//	 for(i=0;i<7;i++){
			//	led=_crol_(led,1);
			//	delay(50000);







				 
	}
	
}