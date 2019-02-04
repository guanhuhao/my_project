#include<stdio.h>
int Max(int a,int b);
int Min(int a,int b);
int main()
{
	int a[5],max,min;
	for(int i=0;i<5;i++)
		scanf("%d",&a[i]);
	max=Max(Max(Max(a[0],a[1]),Max(a[2],a[3])),a[4]);
    min=Min(Min(Min(a[0],a[1]),Min(a[2],a[3])),a[4]);
	printf("%d %d\n",min,max);
	return 0;
}
	


int Max(int a,int b)
{
	if(a<b)
		return b;
	else return a;
}


int Min(int a,int b)
{
	if(a<b)
		return a;
	else return b;
}