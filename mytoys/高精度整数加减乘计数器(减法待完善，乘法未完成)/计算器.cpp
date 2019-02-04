#include<stdio.h>
void ADD(long *p1,long *p2,long *p3)                       //400位高精度正整数加法
{
	int i=0;
	for(i=0;i<100;i++)
	{
		p1[i]=p2[i]+p3[i];
	}
	for(i=0;i<100;i++)
	{
		if(p1[i]>=10000)
		{
			p1[i+1]=p1[i+1]+p1[i]/10000;
			p1[i]=p1[i]%10000;
		}
	}
}

void SUB(long *p1,long *p2,long *p3)                     //400位高精度正整数减法 要求 p2>p1
{
	int i=0;
	for(i=0;i<100;i++)
		p1[i]=p2[i]-p3[i];
	for(i=0;i<200;i++)
	{
		if(p1[i]<0)
		{
			p1[i+1]=p1[i+1]-1;
			p1[i]=p1[i]+10000;
		}
	}
}

void MUL(long *p1,long *p2,long *p3)                     //400位高精度正整数乘法 要求建议不要乘40w以上的数
{
	int i=0
	for(i=0;i<100;i++)
		p1[i]=p2[i]*p3[i];
	for(i=0;i<100;i++)
	{
		if(p1[i]>=10000)
		{
			p1[i+1]=p1[i]/10000;
			p1[i]=p1[i]%10000;
		}
	}
}

int main()
{
	int i;
	long a[100]={0},b[100]={0};
	long *p1,*p2;
	a[0]=10; b[0]=20;
	p1=&a[0];
	p2=&b[0];
	ADD(p1,p1,p2);
	for(i=99;i>-1;i--)
	{
		if(a[i]!=0)
			break;
	}
	for(;i>-1;i--)
	{
		printf("%ld\n",a[i]);
	}

	return 0;
}


