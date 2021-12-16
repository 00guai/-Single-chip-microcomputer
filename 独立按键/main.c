#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;


sbit led=P0^0;
sbit k1=P1^0;//定义按键

void delay(u16 i)
{
	while(i--);
}



void keypros()
{
	if(k1==0)//判断按键是否为低电平
	{
		delay(1000);//消抖
		if(k1==0)
		{
			led=~led;//取反从高电平到低电平，从亮到熄灭
		}
		while(!k1);
	}
}
void main()
{
	led=0;//开始为熄灭
	while(1)
	{
       keypros();		 
	}
	
}