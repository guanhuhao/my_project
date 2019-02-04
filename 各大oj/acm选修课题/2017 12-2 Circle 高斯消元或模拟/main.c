#include <stdio.h>
#include <stdlib.h>
double rate[1010];

int main()
{
    int T;
    double n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&n,&m);
        printf("%.4lf\n",m*(n-m));
    }
    return 0;

}
