#include<stdio.h>
#include<math.h>
int main()
{
	long a,b,i,j,sum1,sum2,num;
	while(scanf("%ld%ld",&a,&b)!=EOF)
	{
		num=0;
		for(i=a;i<=b;i++)
		{
			sum1=0; sum2=0;
			for(j=1;j<sqrt(i);j++)
			{
				if(i%j==0)
					sum1=sum1+j+i/j;           //chongzhi
			}
			sum1=sum1-i;
			for(j=1;j<=sqrt(sum1);j++)
			{
				if(sum1%j==0)
					sum2=sum2+j+sum1/j;           //chongzhi
			}
			sum2=sum2-sum1;
			if(i==sum2 && i!=sum1)
				num++;                      //chongzhi			
		}
		printf("%d\n",num/2);
	}
	return 0;
}