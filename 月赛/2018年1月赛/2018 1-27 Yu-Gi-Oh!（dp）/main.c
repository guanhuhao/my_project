#include <stdio.h>
#include <stdlib.h>
long long niyuan[100005],jiecheng[100005];
long long qpow(long a,long b)
{
    long long ans;
    if(b==1) return a;
    ans=qpow(a,b/2);
    if(b%2==1) return (ans*ans*a)%100003;
    else return (ans*ans)%100003;
}
int init()
{
    int i;
    jiecheng[0]=niyuan[0]=1;
    for(i=1;i<=100003;i++)
    {
        jiecheng[i]=(jiecheng[i-1]*i)%100003;
        niyuan[i]=qpow(jiecheng[i],100001);
    }
    return 0;
}

int main()
{
    int T;
    long long ans,temn,temm;
    long long n,m;
    init();
    scanf("%d",&T);
    while(T--)
    {
        ans=1;
        scanf("%lld%lld",&n,&m);
        while(m!=0)
        {
            temn=n%100003;
            temm=m%100003;
            if(temn<temm) ans=0;
            ans=ans*((jiecheng[temn]*niyuan[temm]%100003)*niyuan[temn-temm]%100003)%100003;
            n=n/100003;
            m=m/100003;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
