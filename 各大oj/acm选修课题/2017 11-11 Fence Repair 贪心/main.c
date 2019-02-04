#include <stdio.h>
#include <stdlib.h>
int cmp ( const void *a , const void *b )
{
    return *(int *)b - *(int *)a; //Ωµ–Ú≈≈–Ú
}

int main()
{
    long long  N,lens[60000],i,j,sum;
    while(scanf("%lld",&N)!=EOF)
    {
        sum=0;
        for(i=0;i<N;i++) scanf("%lld",&lens[i]);
        qsort(lens,N,sizeof(lens[0]),cmp);
        for(i=0;i<N;i++)
        {
            for(j=i;j<N;j++)
                sum=sum+lens[j];
        }
        sum=sum-lens[N-1];
        if(N!=1) printf("%lld\n",sum);
        if(N==1) printf("%lld\n",lens[0]);
    }
    return 0;

}
