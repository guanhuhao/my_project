#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double b,xt,xp,jiao,a;
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        while(N--)
        {
           scanf("%lf%lf%lf",&xp,&xt,&jiao);
           b=tan(jiao);
           a=b*xp/(xt*xt-2*xt*xp);
           printf("%.3lf\n",a*xt*xt*xt/3+b*xt*xt/2+(a*xt*xt+b*xt)*(xp-xt)/2);
        }
    }
    return 0;
}
