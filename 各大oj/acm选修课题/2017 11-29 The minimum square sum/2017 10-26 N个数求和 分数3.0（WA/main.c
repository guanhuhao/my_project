#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long gcd(long long a,long long b);

int main()
{

    long long a[110],b[110],i,j,fenzi,fenmu,zhenshu,tem,n;
    while(scanf("%lld",&n)!=EOF)
    {
        zhenshu=0;

        for(i=0; i<n; i++)    scanf("%lld/%lld",&a[i],&b[i]);
        fenzi=0;
        fenmu=1;

        for(i=0; i<n; i++)
        {
            tem=gcd(fenmu,b[i]);
            fenzi=fenzi*(b[i]/tem)+a[i]*(fenmu/tem);
            fenmu=(fenmu/tem)*b[i];

            zhenshu=zhenshu+fenzi/fenmu;                        //假分数化真分数
            fenzi=fenzi-(fenzi/fenmu)*fenmu;
            //分数化简
            tem=fenzi>0?fenzi:(-fenzi);                               //此时tem相当于分子的绝对值

            j=gcd(tem,fenmu);

            fenzi=fenzi/j;
            fenmu=fenmu/j;

        }

        if(fenzi == 0) printf("%lld\n",zhenshu);
        if(zhenshu==0 && fenzi!=0)  printf("%lld/%lld\n",fenzi,fenmu);
        if(zhenshu != 0 && fenzi!=0) printf("%lld %lld/%lld\n",zhenshu,fenzi,fenmu);

    }
    return 0;
}

long long gcd(long long a,long long b)
{
    if(a==0)    return b;
    else return gcd(b%a,a);
}
