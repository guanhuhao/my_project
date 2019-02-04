#include<stdio.h>
int main()
{
	int a[4],i,j,k;
	char num[4][3][3];
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF)
	{
		for(i=0;i<4;i++)
		{
			if(a[i]==1)
			{
				num[i][0][0]=num[i][0][1]=num[i][0][2]=num[i][1][0]=num[i][1][1]=num[i][2][0]=num[i][2][1]=' ';
				num[i][1][2]=num[i][2][2]='|';
			}
			if(a[i]==2)
			{
				num[i][0][0]=num[i][0][2]=num[i][1][0]=num[i][2][2]=' ';
				num[i][2][0]=num[i][1][2]='|';
				num[i][0][1]=num[i][1][1]=num[i][2][1]='_';
			}
			if(a[i]==3)
			{
				num[i][0][0]=num[i][0][2]=num[i][1][0]=num[i][2][0]=' ';
				num[i][1][2]=num[i][2][2]='|';
				num[i][0][1]=num[i][1][1]=num[i][2][1]='_';
			}
			if(a[i]==4)
			{
				num[i][0][0]=num[i][0][1]=num[i][0][2]=num[i][2][0]=num[i][2][1]=' ';
				num[i][1][0]=num[i][1][2]=num[i][2][2]='|';
				num[i][1][1]='_';
			}
			if(a[i]==5)
			{
				num[i][0][0]=num[i][0][2]=num[i][2][0]=num[i][1][2]=' ';
				num[i][1][0]=num[i][2][2]='|';
				num[i][1][1]=num[i][0][1]=num[i][2][1]='_';
			}
			if(a[i]==6)
			{
				num[i][0][0]=num[i][0][2]=num[i][1][2]=' ';
				num[i][1][0]=num[i][2][2]=num[i][2][0]='|';
				num[i][1][1]=num[i][0][1]=num[i][2][1]='_';
			}
			if(a[i]==7)
			{
				num[i][0][0]=num[i][0][2]=num[i][1][0]=num[i][1][1]=num[i][2][0]=num[i][2][1]=' ';
				num[i][1][2]=num[i][2][2]='|';
				num[i][0][1]='_';
			}
			if(a[i]==8)
			{
				num[i][0][0]=num[i][0][2]=' ';
				num[i][1][0]=num[i][2][0]=num[i][1][2]=num[i][2][2]='|';
				num[i][1][1]=num[i][0][1]=num[i][2][1]='_';
			}
			if(a[i]==9)
			{
				num[i][0][0]=num[i][0][2]=num[i][2][0]=' ';
				num[i][1][0]=num[i][1][2]=num[i][2][2]='|';
				num[i][1][1]=num[i][0][1]=num[i][2][1]='_';
			}
			if(a[i]==0)
			{
				num[i][0][0]=num[i][0][2]=num[i][1][1]=' ';
				num[i][1][0]=num[i][2][0]=num[i][1][2]=num[i][2][2]='|';
				num[i][0][1]=num[i][2][1]='_';
			}
		}

		for(i=0;i<3;i++)
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<3;k++)
					printf("%c",num[j][i][k]);
			}
			printf("\n");
		}

	}
	return 0;


}


