#include<stdio.h>
int main()
{
	int i;
	char a[3],max,min,mid;
	while(gets(a)!=NULL)
	{
		max=0,min=0,mid=0;
		max = ( (a[0] > a[1] ? a[0]:a[1] ) > a[2] ? (a[0]>a[1]?a[0]:a[1]):a[2]);
		min = ( (a[0] < a[1] ? a[0]:a[1] ) < a[2] ? (a[0]<a[1]?a[0]:a[1]):a[2]);
		mid = ( a[0]+a[1]+a[2] ) - max - min;
		printf("%c %c %c\n",min,mid,max);
	}
	return 0;
}