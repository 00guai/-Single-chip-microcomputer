#include "reg52.h"
#include "intrins.h"


typedef unsigned char u8;
typedef unsigned int u16;
sbit beep=P0^0;


void Delay1us(u16 k)		//@12.000MHz
	{while (k--)
			
				{
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				}
}



void main()
{
	
	while(1)
	{
		beep=~beep;
		Delay1us(10);
		beep=0;
	  Delay1us(5);
	}
	
}