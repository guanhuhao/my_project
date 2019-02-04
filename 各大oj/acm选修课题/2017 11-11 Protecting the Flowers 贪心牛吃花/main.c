#include <stdio.h>
#include <stdlib.h>
long long T[2100000],S[110000];    //T为时间 S为消耗速率
int main()
{
    int N,i;
    long long sumhua,tem,sums,count,min;
    while(scanf("%d",&N)!=EOF)
    {
        sumhua=0;
        sums=0;

        for(i=0; i<N; i++) scanf("%lld%lld",&T[i],&S[i]);

        for(i=0; i<N; i++) sums=sums+S[i];
        for(count=0; count<N; count++)
        {

            for(min=20000000000000000,i=0; i<N; i++)
            {
                if(T[i]==-1) continue;
                if(min>T[i]*(sums-S[i]))
                {
                    min=T[i]*(sums-S[i]);
                    tem=i;
                }
            }
            sumhua=sumhua+min*2;
            sums=sums-S[tem];
            T[tem]=-1;
        }
        printf("%lld\n",sumhua);

    }
    return 0;

}
