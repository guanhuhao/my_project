#include<stdio.h>
int main()
{
	int N,M,a[50]={0},i,j,max=0;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i+j+2]++;
		}
	}
	for(i=0;i<M+N;i++)   max=max>a[i]?max:a[i];
	for(i=0;i<M+N;i++)
	{
		if(a[i]==max)
			printf("%d\n",i);
	}
	return 0;

}