#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;


sbit led=P0^0;
sbit k1=P1^0;//���尴��

void delay(u16 i)
{
	while(i--);
}



void keypros()
{
	if(k1==0)//�жϰ����Ƿ�Ϊ�͵�ƽ
	{
		delay(1000);//����
		if(k1==0)
		{
			led=~led;//ȡ���Ӹߵ�ƽ���͵�ƽ��������Ϩ��
		}
		while(!k1);
	}
}
void main()
{
	led=0;//��ʼΪϨ��
	while(1)
	{
       keypros();		 
	}
	
}