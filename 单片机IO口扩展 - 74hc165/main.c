#include<reg52.h>
#include<intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define GPIO_LED P0//����


sbit IN_PL=P1^6;//��λ����2�ܽ�
sbit IN_DATA=P1^7;//����ܽ�
sbit SCK=P3^6;//ʱ�ӹܽ�

void delay(u16 i)
{
	while(i--);
}


u8 Read74HC165()//��ȡ165������  u8�Ƿ��ص��ֽ�ֵ����
{
	u8 indata;
	u8 i;
	IN_PL=0;//��λ�������ڵ͵�ƽ��ʹ��
	_nop_();//��ʱһ����
	IN_PL=1;//������
	_nop_();
	 indata=0;
	
	for(i=0;i<8;i++)//��λ   ��8�ֽ�����ѭ��8��
	{
		indata=indata<<1;
		SCK=0;
		_nop_();
		
		indata|=IN_DATA;//�ߵ�λ�Ż����Ӱ��
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
			  GPIO_LED=~h165Value;//ȡ����1����������ȥ��7������
		}
	}
} 