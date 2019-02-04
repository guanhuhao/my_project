#include<stdio.h>
int main()
{
	int num,i;
	while(scanf("%d",&num) != EOF)
	{
		for(i=0;i<num/100;i++)
			printf("B");
		for(i=0;i<((num/10)%10);i++)
			printf("S");
		for(i=0;i<num%10;i++)
			printf("%d",i+1);
		printf("\n");
	}
	return 0;
}