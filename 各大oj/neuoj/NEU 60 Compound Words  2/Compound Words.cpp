#include<stdio.h>
#include<string.h>
char a[120000][100]={0};
int main()
{
    int i=0,j=0,k=0,l=0,num=0,flag=0;
	char tem[200]={0};
	while(gets(a[i])!=NULL)
	{
		i++;
	}
	num=i;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if( strncmp(a[j],a[i],strlen(a[i]) ) != 0)
				break;                                            //如果这个能通过说明a[i]的前几项和a[j]前几项吻合
			else
			{
				for(k=0;k<num;k++)
				{
					if(a[k][0] < a[j][strlen(a[i])])
						continue;					
					if(a[k][0] > a[j][strlen(a[i])])
						break;

					strcat(tem,a[i]);
					strcat(tem,a[k]);
					if( strcmp(a[j],tem) == 0)
						printf("%s\n",a[j]);
					for(l=0;tem[l]!=0;l++)
					{
						tem[l]=0;
					}
				}
			}
		}

			

	}
	
	return 0;
}














/*		if(a[i][0] != a[i+1][0])
		{
			continue;
			flag=i+1;
		}
		for(j=flag;j<i;j++)
		{
			if (strncmp(a[j],a[i],strlen(a[i]))==0)
			{
				for(k=0;k<num;k++)
				{
					strcat(tem,a[j]);
					strcat(tem,a[k]);
					if(strcmp(a[i],tem)==0)
						printf("%s\n",a[i]);
					printf("%s\n",tem);
					for(l=0;tem[l]!=0;l++)
						tem[l]=0;
				}
	
			}
		}
		*/
			
