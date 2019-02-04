#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long  p;
    while(scanf("%lld",&p)!=EOF)
    {
        if(p==2) printf("2\n");
        else if(p%4==1) printf("%lld\n",p);
        else printf("%lld\n",p*p*2);
    }
    return 0;
}
