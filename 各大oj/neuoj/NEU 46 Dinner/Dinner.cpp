#include<stdio.h>
#include<string.h>
int main()
{
	int i,num,j;
	char name[100][100];

	while(scanf("%d",&num)!=EOF)
	{
		
		j=0;
		int b[100]={0};
		for(i=0;i<num;i++)
			scanf("%s",name[i]);
		for(i=0;i<num;i++)
		{			
			if(strcmp(name[i],"bowl")==0||strcmp(name[i],"knife")==0||strcmp(name[i],"chopsticks")==0||strcmp(name[i],"fork")==0)
			{
				printf("%s ",name[i]);
			}

		}
		printf("\n");
		
	}
	return 0;
}