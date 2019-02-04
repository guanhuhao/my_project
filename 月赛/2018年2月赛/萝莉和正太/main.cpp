#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T,i;
    long long n,k,ans,zu,tem;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld%lld",&n,&k);
        zu=(1+n)*(n+1)-1;
        tem=n/(k+1);
        ans=zu-tem*(tem-1)*2-tem-2*tem;
        printf("Case #%d: %lld\n",i,(n-tem)*2+(tem*n-tem*tem)*2);
    }
    return 0;
}
