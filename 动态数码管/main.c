#include"reg52.h"
#include"intrins.h"

typedef unsigned int u16;
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;//38译码器

 
u8 code smgduan[16]={0x3f , 0x06, 0x5b,  0x4f,  0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//共阴   段码数据


void delay(u16 i)
{
	while(i--);
		
}



void DigDisplay()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)
		{
			case (0):
			LSA=0;LSB=0;LSC=0;break;//当i等于0，就执行这个后，break后i+1执继续执行下一段
			case(1):
			LSA=1;LSB=0;LSC=0;break;//反着读
			case(2):
			LSA=0;LSB=1;LSC=0;break;
			case (3):
			LSA=1;LSB=1;LSC=0;break;
			case(4):
			LSA=0;LSB=0;LSC=1;break;
			case(5):
			LSA=1;LSB=0;LSC=1;break;
			case (6):
			LSA=0;LSB=1;LSC=1;break;
			case(7):
			LSA=1;LSB=1;LSC=1;break;

		}
		P0= smgduan[i];
		delay(100);
				P0=0*00;//清0，防止重影 
	}
	
}
void main()
{
	P0= ~smgduan[0];//单独的数码管是共阳的，用取反符号得共阴
	while(1)
	{
		DigDisplay();
	}
}