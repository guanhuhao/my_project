#include<stdio.h>
#include<string.h>
int main()
{
	int CASE,t=0,i=0,num=0,j=0,count=0,output=0,flag=0;
	scanf("%d",&CASE);
	getchar();
	for(count=0;count<CASE;count++)
	{
		output=0;  flag=0;  num=0;
		char name[200][20]={0},chatter[200][20]={0},char a[100][200]={0};
		while(1)
		{
			gets(a[num]);
			if(a[num][0]=='\0')
				break;
			num++;
		}
		for(i=0;i<num;i++)
		{
			for(j=0;a[i][j]!=':';j++)
				name[i][j]=a[i][j];
		}

		for(i=0;i<num;i++)
		{
			flag=0;
			for(j=0;j<output;j++)
			{
				if(strcmp(name[i],chatter[j])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==1) continue;
			strcpy(chatter[output],name[i]);
			output++;
		}

		printf("CASE #%d: %d\n",count+1,output);


		
	}
	return 0;

}