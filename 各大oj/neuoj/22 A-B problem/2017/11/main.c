#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long N,a,b;
    scanf("%lld",&N);
    while(N--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",(a-b)>0?a-b:b-a);
    }
    return 0;
}
