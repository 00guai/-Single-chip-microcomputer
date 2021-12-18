#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define GPIO_LED P0//定义


sbit IN_PL=P1^6;//移位置入2管脚
sbit IN_DATA=P1^7;//输出管脚
sbit SCK=P3^6;//时钟管脚

void delay(u16 i)
{
	while(i--);
}


u8 Read74HC165()//读取165的数据  u8是返回的字节值··
{
	u8 indata;
	u8 i;
	IN_PL=0;//移位，置入在低电平下使用
	_nop_();//延时一周期
	IN_PL=1;//再拉高
	_nop_();
	 indata=0;
	
	for(i=0;i<8;i++)//移位   有8字节所以循环8次
	{
		indata=indata<<1;
		SCK=0;
		_nop_();
		
		indata|=IN_DATA;//高电位才会产生影响
		SCK=1;
	}
	return indata;
}




void main()
{
	u8 h165Value;
	GPIO_LED=0;
	while(1)
	{
		if(h165Value!=0xff)
		{
			  GPIO_LED=~h165Value;//取反有1个灯亮，不去反7个灯亮
		}
	}
} 