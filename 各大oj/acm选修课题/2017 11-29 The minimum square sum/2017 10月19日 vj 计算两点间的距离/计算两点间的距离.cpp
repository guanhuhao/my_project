#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,x2,y2,length;
	while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		length=sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));
		printf("%.2lf\n",length);
	}
	return 0;
}