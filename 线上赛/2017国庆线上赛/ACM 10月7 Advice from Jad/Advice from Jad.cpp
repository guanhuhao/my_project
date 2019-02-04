#include<stdio.h>
#include <string.h>
char a[10][120000],b[10][120000];
int main()
{
	int CASE,N,M,i,j,k,flag=0,tem=0;
	scanf("%d",&CASE);
	while(tem<CASE)
	{
		scanf("%d%d",&N,&M);
		getchar();
		for(i=0;i<N;i++)
			gets(a[i]);
		for(i=0;i<M;i++)
			gets(b[i]);
		
		printf("Case #%d:\n",tem+1);
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{	
				flag=0;
				for(k=0;a[j][k]!=EOF;k++)
				{
					if(strncmp(a[j], b[i], strlen(a[j]))!=0)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					printf("This is an easy problem.\n");
					flag=2;
				}
				if(flag==2)  break;
			}
			if(flag==1) printf("This problem may be somewhat difficult.\n");
		}
		printf("\n");

		tem++;
		
	}
	return 0;
}













/*
#include<stdio.h>
char a[10][120000],b[10][120000];
int main()
{
	int CASE,N,M,i,j,k,flag=0;
	scanf("%d",&CASE);
	while(CASE--)
	{
		scanf("%d%d",&N,&M);
		for(i=0;i<N;i++)
			gets(a[i]);
		for(i=0;i<M;i++)
			gets(b[i]);
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{	
				flag=0;
				for(k=0;a[j][k]!=EOF;k++)
				{
					if(a[j][k]!=b[i][k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					printf("This is an easy problem.\n");
					flag=2;
				}
				if(flag==2)  break;
			}
			if(flag==1) printf("This problem may be somewhat difficult.\n");
		}
		printf("1");
	}
	return 0;
}
*/
