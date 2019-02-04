#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,i,j,num,flag=0;
	while(scanf("%d%d",&a,&b) != EOF )
	{
		if(b==0 && a==0) continue;
		flag=0;
		for(i=a;i<=b;i++)
		{
			num=i*i+i+41;
			for(j=2;j<=sqrt(num);j++)
			{
				if(num%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}
		if(flag==0) printf("OK\n");
		if(flag==1) printf("Sorry\n");
	}
	return 0;
}