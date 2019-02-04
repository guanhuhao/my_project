#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    double a,b;
    while(scanf("%d",&T)!=EOF)
    {

        while(T--)
        {
            scanf("%lf%lf",&a,&b);
            printf("%lf\n",a/b);
        }
    }
    return 0;

}
