#include<stdio.h>
int main()
{
	long i,j,flag=0;
	double k,b,x1,x2,y1,y2,x,y;
	scanf("%lf%lf%lf%lf%lf%lf",&x,&y,&x1,&y1,&x2,&y2);
	for(i=0;i<x;i++)
	{
		for(j=0;j<x;j++)
		{
			if(j-i==0)
			{
				if((i-x1)*(i-x2)<0)
				{
					flag=1;
					break;
				}
				else continue;
			}
			k=y/(j-i);
			b=-i*(k);
			if((y1-k*x1-b)*(y2-k*x2-b)<0) 
			{
				flag=1;
				break;
			}



		}
		if(flag==1) break;
	}
	printf("%ld 0 %ld %0.f\n",i,j,y);
	return 0;
}
