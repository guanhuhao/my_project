#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long a[110],b[110],i,j,n,fenzi[110],fenmu,sum,outfenzi,outzhenshu,tem;
    while(scanf("%lld",&n)!=EOF)
    {
        sum=0;
        fenmu=1;
        for(i=0;i<n;i++)
        {
            scanf("%lld/%lld",&a[i],&b[i]);
        }
        for(i=0;i<n;i++)
        {
            fenzi[i]=a[i];
            for(j=0;j<n;j++)
            {
                if(j!=i) fenzi[i]=fenzi[i]*b[j];
            }
        }
        for(i=0;i<n;i++) fenmu=fenmu*b[i];
        for(i=0;i<n;i++) sum=sum+fenzi[i];
        outzhenshu=sum/fenmu;
        outfenzi=sum-outzhenshu*fenmu;
        tem=sqrt(abs(fenzi));
        for(i=2;i<=tem;i++)
        {
            if(outfenzi%i==0 && fenmu%i==0)
            {
                outfenzi=outfenzi/i;
                fenmu=fenmu/i;
                i--;
                tem=sqrt(abs(outfenzi));
            }
        }
        if(fenmu%outfenzi==0) {
            fenmu=fenmu/outfenzi;
            outfenzi=1;
        }
        if(outzhenshu==0) printf("%lld/%lld\n",outfenzi,fenmu);
        else printf("%lld %lld/%lld\n",outzhenshu,outfenzi,fenmu);


    }
    return 0;
}
