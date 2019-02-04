#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.8
int main()
{
    double r,h,w,t;
    while(scanf("%lf%lf%lf",&r,&h,&w)!=EOF)
    {
        t=sqrt(2*h/g);
        printf("%.2lf\n",sqrt((w*r*t)*(w*r*t)+r*r));
    }
    return 0;
}
