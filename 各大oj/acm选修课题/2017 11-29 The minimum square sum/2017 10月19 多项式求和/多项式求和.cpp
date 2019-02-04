#include <stdio.h>
int main()
{
	int CASE,num,i;
	double sum;
	scanf("%d",&CASE);
	while(CASE--)
	{
		sum=0;
		scanf("%d",&num);
		for(i=1;i<=num;i++)
		{
			if(i%2==0) 
				sum=sum-1/(double)i;
			else
				sum=sum+1/(double)i;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}