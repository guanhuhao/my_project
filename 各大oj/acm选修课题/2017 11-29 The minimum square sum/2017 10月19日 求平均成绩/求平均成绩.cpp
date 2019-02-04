#include <stdio.h>
int main()
{
	int a[55][6],n,m,i,j,sum,num,flag;
	double aver[6];
	while(scanf("%d%d",&n,&m) != EOF)
	{
		num=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		}
		for(i=0;i<n;i++)
		{
			sum=0;
			for(j=0;j<m;j++)
				sum=sum+a[i][j];
			if(i==0) 
				printf("%.2lf",(double)sum/m);
			else 
				printf(" %.2lf",(double)sum/m);
		}
		printf("\n");
		for(i=0;i<m;i++)
		{
			sum=0;
			for(j=0;j<n;j++)
				sum=sum+a[j][i];
			aver[i]=(double)sum/n;
			if(i==0)
				printf("%.2lf",aver[i]);
			else
				printf(" %.2lf",aver[i]);
		}
		printf("\n");
		for(i=0;i<n;i++)
		{
			flag=0;
			for(j=0;j<m;j++)
			{
				if(a[i][j]<aver[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==0) num++;
		}
		printf("%d",num);
		printf("\n\n");
		
	}
	return 0;
}