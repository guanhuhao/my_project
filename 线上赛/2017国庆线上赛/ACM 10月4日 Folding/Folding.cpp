#include<stdio.h>
int main()
{
	int fold1,fold2,flag=0;
	long w1,w2,h1,h2,max1,max2,min1,min2;
	scanf("%ld%ld%ld%ld",&w1,&h1,&w2,&h2);
	max1=w1>h1?w1:h1;
	max2=w2>h2?w2:h2;
	min1=w1<h1?w1:h1;
	min2=w2<h2?w2:h2;
	if((max1<max2) || (min1<min2)) flag=1;
	for(fold1=0;max1>max2;fold1++)
		max1=(max1+1)/2;
	for(fold2=0;min1>min2;fold2++)
		min1=(min1+1)/2;
	if(flag==1) printf("-1\n");
	else printf("%d\n",fold1+fold2);
	return 0;


}