#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long  i,n,m,tem1,tem2,CASE;
    scanf("%lld",&CASE);
    while(CASE--)
    {
        scanf("%lld%lld",&n,&m);
        tem1=tem2=1;
        for(i=0;i<m-n-1;i++)
        {
            tem1=tem1+tem2;
            tem2=tem1-tem2;
        }
        printf("%lld\n",tem1);
    }
    return 0;
}
