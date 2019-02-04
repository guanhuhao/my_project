#include<stdio.h>
int main()
{
	int a,b,i,n=0;
	while( scanf("%d%d",&a,&b)!=EOF )
	{
		n=0;
		for(i=a;i<=b;i++)
		{
			if(i==(i%10)*(i%10)*(i%10) + ((i/10)%10)*((i/10)%10)*((i/10)%10) + (i/100)*(i/100)*(i/100)) 
			{
				if(n!=0) printf(" ");
				printf("%d",i);
				n++;
			}
		}
		if(n==0) printf("no\n"); else printf("\n");
	}
	return 0;
}