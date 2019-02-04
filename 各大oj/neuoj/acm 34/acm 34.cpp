#include<stdio.h>
int main()
{
	int three,five,seven,i;
	scanf("%d",&three);
	scanf("%d",&five);
	scanf("%d",&seven);
	for(i=0;1==1;i++)
	{
		if((seven+7*i-five)%5==0&&(seven+7*i-three)%3==0)
			break;
	}
	printf("%d\n",seven+7*i);
	return 0;
}
			