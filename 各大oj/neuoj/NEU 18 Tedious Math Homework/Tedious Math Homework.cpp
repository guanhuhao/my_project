#include<stdio.h>
int main()
{
	int n,i,j,NO;
	double a[4][3],k1,k2,k3;
	scanf("%d",&n);
	for(NO=1;NO<=n;NO++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<3;j++)
				scanf("%lf",&a[i][j]);
		}
		k1=(a[0][0]-a[1][0])/(a[0][1]-a[1][1]);  //  x/y
		k2=(a[0][0]-a[1][0])/(a[0][2]-a[1][2]);  //  x/z
		k3=(a[0][1]-a[1][1])/(a[0][2]-a[1][2]);  //  y/z
		for(i=2;i<4;i++)
		{
			if (( a[0][0] - a[i][0] ) / ( a[0][1] - a[i][1] )<k1-1e-6 || ( a[0][0] - a[i][0] ) / ( a[0][1] - a[i][1] )>k1 + 1e-6)
			{
				printf("Case #%d: NO\n",NO);
				break;
			}
			else if (( a[0][0] - a[i][0] ) / ( a[0][2] - a[i][2] )<k2-1e-6 || ( a[0][0] - a[i][0] ) / ( a[0][2] - a[i][2] )>k2 + 1e-6)
			{
				printf("Case #%d: NO\n",NO);
				break;
			}
			else if (( a[0][1] - a[i][1] ) / ( a[0][2] - a[i][2] )<k3-1e-6 || ( a[0][1] - a[i][1] ) / ( a[0][2] - a[i][2] )>k3 + 1e-6)
			{
				printf("Case #%d: NO\n",NO);
				break;
			}
			else if(i==3) printf("Case #%d: YES\n",NO);
		}
		

	}
	return 0;
}