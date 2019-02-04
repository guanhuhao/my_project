#include<stdio.h>
int main()
{
	int CASE;
	double p1,p2,rate=0,i,tem=1,j;
	scanf("%d",&CASE);
	while(CASE--)
	{
		scanf("%lf%lf",&p1,&p2);
		tem=(1-p1)*(1-p2);
		if(p1==1&&p2==1)
			printf("%.3f\n",1);
		else 
		{
			for(i=0;i<10;i++)
			{
				rate = rate + tem;
				for(j=0;j<i+1;j++)
					tem=tem*tem*p1*p2;
			}

			printf("%.3f\n",rate);
		}
		tem=1;
		rate=0;
	}
	return 0;

}