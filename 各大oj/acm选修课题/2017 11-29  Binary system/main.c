#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[70];
    long long i,lens,sum;
    while(scanf("%s",a)!=EOF)
    {
        sum=0;
        for(i=0;a[i]=='0'||a[i]=='1';i++);
        lens=i;
        for(i=0;i<lens;i++)
        {
            if(a[i]=='0')
            sum=sum*2;
            if(a[i]=='1')
                sum=sum*2+1;

        }
        printf("%lld\n",sum);
    }
    return 0;
}
