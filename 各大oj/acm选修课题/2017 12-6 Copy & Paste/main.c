#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,count;
    double n;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            count=0;
            scanf("%lf",&n);
            while(n>1)
            {
                count++;
                n=n/2;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
