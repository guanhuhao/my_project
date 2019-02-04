#include<stdio.h>
#include<string.h>
int main()
{
	int CASE,sum1=0,sum2=0,i,j=0,k=0,flag,max1=0,max2=0;
	char a[5000],b[5000];
	scanf("%d",&CASE);
	getchar();
	while(CASE--)
	{
		gets(a);
		gets(b);
		max1=0;
		max2=0;

		for(k=0;k<strlen(a);k++)
		{
			flag=0;
			sum1=0;
			for(i=k;a[i]!=0;i++)
			{
				for(j=flag;b[j]!=0;j++)
				{
					if(a[i]==b[j])
					{
						sum1++;
						flag=j+1;
						break;
					}
				}
			}
			max1=max1>sum1?max1:sum1;
		}

		for(k=0;k<strlen(b);k++)
		{
			flag=0;
			sum2=0;
			for(i=k;b[i]!=0;i++)
			{
				for(j=flag;a[j]!=0;j++)
				{
					if(a[j]==b[i])
					{
						sum2++;
						flag=j+1;
						break;
					}
				}
			}
			max2=max2>sum2?max2:sum2;
		}
		printf("%d\n\n",max1>max2?max1:max2);

	}
	return 0;
}