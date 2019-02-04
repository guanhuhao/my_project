#include<stdio.h>
int main()
{
	int n,a[1000][2],i,j,tema,temb;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
				scanf("%d",&a[i][j]);
		}
		for(i=0,tema=0,j=1;i<1000;i++)
		{
			if(a[i][0]==j)
			{
				tema++;
				j=a[i][1];
			}
		}
		for(i=0,temb=0,j=2;i<1000;i++)
		{
			if(a[i][0]==j)
			{
				temb++;
				j=a[i][1];
			}
		}
		if(tema==temb)
			printf("You are my brother\n");
		else if(tema<temb)
			printf("You are my younger\n");
		else printf("You are my elder\n");



	}
	return 0;
}