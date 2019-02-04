#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,c,max,min1,min2;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        min1=min2=max=0;
        max=(a>b?a:b)>c?(a>b?a:b):c;
        min1=(a<b?a:b)<c?(a<b?a:b):c;
        min2=a+b+c-min1-max;
        if(max>=(a+b+c-max)) printf("N\n");
        else if(max*max-min1*min1-min2*min2>0) printf("D\n");
        else if(max*max-min1*min1-min2*min2<0) printf("R\n");
        else if(max*max-min1*min1-min2*min2==0) printf("Z\n");
    }
    return 0;
}
