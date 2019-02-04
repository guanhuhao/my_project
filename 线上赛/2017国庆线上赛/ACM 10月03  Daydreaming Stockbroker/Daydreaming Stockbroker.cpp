#include<stdio.h>
int main()
{
	long long n,m[500],i=0,min,max,gu=0,money=100;

	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&m[i]);
	i=0;
	while(i<n)
	{
		min=m[i];
		i++;
		for(;i<n;i++)
		{
			if(m[i]<=min) min=m[i];
			else break;
		}
		if(i==n)	break;
		gu=money/min;
		money=money-gu*min;
		max=m[i];
		i++;
		for(;i<n;i++)
		{
			if(m[i]>= max) max=m[i];
			else break;
		}
		money=money+gu*max;
		gu=0;

    }
	printf("%lld\n",money);
	return 0;




}
