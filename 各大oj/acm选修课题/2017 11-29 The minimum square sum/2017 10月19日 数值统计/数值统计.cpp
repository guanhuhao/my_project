#include<stdio.h>
int main()
{
	int n,zheng,fu,zero,i;
	float a;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) continue;
		zheng=fu=zero=0;
		for(i=0;i<n;i++)
		{
			scanf("%f",&a);
			if(a>0) zheng++;
			if(a<0) fu++;
			if(a==0) zero++;
		}
		printf("%d %d %d\n",fu,zero,zheng);
	}
	return 0;
}