#include <iostream>
#include <cstdio>
using namespace std;
int gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    long long n,m;
    long long ans;
    long long i;
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ans=0;
        //printf("%d\n",gcd(n,m));
        for(i=1;i<=n;i++)
        {
            if(gcd(m,i)!=1) continue;
            ans=(ans+(i*i+i))%1000000007;
            //printf("%lld\n",i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
