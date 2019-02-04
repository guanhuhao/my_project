#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long sum=1;
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=1;
        for(i=0;i<n;i++)
        {
            sum=sum*2;
        }
        printf("2^%d = %lld\n",n,sum);
    }
    return 0;
}
