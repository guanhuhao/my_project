#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long  i,n,tem1,tem2;
    while(scanf("%lld",&n)!=EOF)
    {
        tem1=tem2=1;
        for(i=0;i<n-1;i++)
        {
            tem1=tem1+tem2;
            tem2=tem1-tem2;
        }
        printf("%lld\n",tem1);
    }
    return 0;
}
