#include<stdio.h>
int main()
{
	int h,min,s,C1,C2;
	while(scanf("%d%d",&C1,&C2)!=EOF)
	{
		s=((C2-C1+50)/100)%60;
		min=((C2-C1+50)/6000)%60;
		h=(C2-C1+50)/360000;
		printf("%02d:%02d:%02d\n",h,min,s);
	}
	return 0;

	

}