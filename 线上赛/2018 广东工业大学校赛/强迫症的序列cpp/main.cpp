#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    long long sum;
    int len;
    long long ans;
    int _max;
    long long a[100010];
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        ans=0;
        scanf("%d",&len);
        for(int i=0;i<len;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+len);
        _max=a[len-1];
        for(int i=0;i<len;i++) {ans=ans+a[i]-a[0];sum=sum+a[len-1]-a[i];}
        printf("%lld %lld\n",ans,(ans*(len-1)-sum)/len+_max);
    }
    return 0;
}
