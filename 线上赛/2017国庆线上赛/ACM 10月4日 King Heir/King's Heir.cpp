#include<stdio.h>
int main()
{
	int D,M,Y,i,d[100],m[100],y[100],mind=-1,minm=-1,miny=-1,n,NO=-1;
	scanf("%d%d%d%d",&D,&M,&Y,&n);
	for(i=0;i<n;i++)
	scanf("%d%d%d",&d[i],&m[i],&y[i]);
	for(i=0;i<n;i++)
	{
		if(y[i] > Y-18)		continue;
		if((y[i] == Y-18) && (m[i]>M)) 		continue;
		if((y[i] == Y-18) && (m[i]==M) && (d[i]>=D) ) continue;

		if(y[i] < miny) continue;
		else if((y[i] == miny) && (m[i]<minm)) continue;
		else if((y[i] == miny) && (m[i]==minm) && (d[i]<=mind) ) continue;

		miny=y[i];  minm=m[i];  mind=d[i];  NO=i+1;



	}
	printf("%d\n",NO);
	return 0;


}