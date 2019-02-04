#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long i,n,t,sum,tem;
    scanf("%lld",&t);
    while(t--)
    {
        sum=1;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&tem);
            sum=sum*tem;
        }
        if(sum<=100000000) printf("AC\n");
        else printf("TLE\n");

    }
    return 0;
}
