#include<stdio.h>
#include<string.h>
char a[120000][100]={0};
int main()
{
    int i=0,j=0,k=0,num=0;
	char tem[200]={0};
	while(gets(a[i])!=NULL)
	{
		i++;
	}
	num=i;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(i==j)
				continue;
			strcat(tem,a[i]);
			strcat(tem,a[j]);
			for(k=i;k<num;k++)
			{
				if(strcmp(tem,a[k])==0)
					printf("%s\n",a[k]);
				if(tem[0]!=a[k][0])
					break;
			}
			for(k=0;k<200;k++)
				tem[k]=0;
		}
	}
	
	return 0;
}