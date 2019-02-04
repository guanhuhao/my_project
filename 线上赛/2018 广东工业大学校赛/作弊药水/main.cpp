#include <iostream>
#include <cstdio>
using namespace std;
long long qpow(long long a,long long b)
{
    int base=a;
    long long ans=1;
    while(b!=0)
    {
        if(b%2==1)  ans=(ans*base)%1000000007;
        base=(base*base)%1000000007;
        b=b/2;
    }
    return ans;
}
int main()
{
    int a,ap,b,bp;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&a,&ap,&b,&bp);
        //printf("%lld\n",qpow(2,10));
        if(qpow(a,ap)==qpow(b,bp))
            printf("Yes\n");
        else printf("NO\n",qpow(a,ap),qpow(b,bp));
    }
    return 0;
}
