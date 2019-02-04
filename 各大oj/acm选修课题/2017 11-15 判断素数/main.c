#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    long long N,a,i,flag,tem;
    scanf("%lld",&N);
    while(N--)
    {
        flag=0;

        scanf("%lld",&a);
        if(a==1) flag=1;

        tem=sqrt(a);
        for(i=2;i<=(tem+9)&&i<a;i++)
        {
            if(a%i==0) {flag=1;break;}
        }
        if(flag==1) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
