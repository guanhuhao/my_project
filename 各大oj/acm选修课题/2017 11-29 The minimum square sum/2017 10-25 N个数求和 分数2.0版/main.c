#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long i,j,n,a[110],b[110],fenzi,fenmu,zhenshu,tem,min,max;
    while(scanf("%lld",&n)!=EOF)
    {

        zhenshu=0;
        for(i=0; i<n; i++)
        {
            scanf("%lld/%lld",&a[i],&b[i]);
        }
        fenzi=a[0];
        fenmu=b[0];
        for(i=1; i<n; i++)
        {
            min=fenmu<b[i]?fenmu:b[i];
            max=fenmu+b[i]-min;

            fenzi=fenzi*b[i]+a[i]*fenmu;

            fenmu=fenmu*b[i];
            zhenshu=fenzi/fenmu+zhenshu;
            fenzi=fenzi-(fenzi/fenmu)*fenmu;
            if(fenzi==0&&i<n-1)
            {
                i++;
                fenzi=a[i];
                fenmu=b[i];
            }

            for(j=2; j<=fenzi; j++)                //Ô¼·Ö
            {
                if(fenzi%j==0 && fenmu%j==0)
                {
                    fenzi=fenzi/j;
                    fenmu=fenmu/j;
                    j--;

                }
            }

            if(fenzi!=0&&fenmu%fenzi==0)
            {
                fenmu=(fenmu/fenzi)>0?(fenmu/fenzi):(-fenmu/fenzi);
                if(fenzi<0) fenzi=-1;
                else fenzi=1;
            }

        }
        zhenshu=fenzi/fenmu+zhenshu;
        fenzi=fenzi-(fenzi/fenmu)*fenmu;
        if(zhenshu==0&&fenzi!=0)  printf("%lld/%lld\n",fenzi,fenmu);
        if(fenzi==0) printf("%lld\n",zhenshu);
        if(zhenshu!=0 && fenzi!=0) printf("%lld %lld/%lld\n",zhenshu+1,fenzi,fenmu);


    }
    return 0;
}
