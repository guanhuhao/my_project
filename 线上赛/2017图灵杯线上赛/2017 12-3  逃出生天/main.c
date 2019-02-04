#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,T,m,i;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        m=1;
        for(i=1; i<=(n-1); i++)
        {
            m=(m*i)%n;
            if(m==0) break;
        }
        if(m==0) printf("escape\n");
        else printf("trapped\n");

    }
    return 0;

}
