#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

u8 code smgduan[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,
0x7c,0x39,0x5e,0x79,0x71};//共阴


void main()
{
	P0= ~smgduan[1];//单独的数码管是共阳的，用取反符号得共阴
	while(1)
	{
		
	}
}