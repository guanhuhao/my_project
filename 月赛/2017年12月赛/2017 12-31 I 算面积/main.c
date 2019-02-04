#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#define PI 3.14159265358979323846264338327950288
int main()
{
    int T,i;
    double input,PI=acos(-1);
    printf("%.20lf",PI);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lf",&input);
        printf("Case #%d: %lld\n",i,(long long)((input/(PI*4))*input));
    }
    return 0;
}

