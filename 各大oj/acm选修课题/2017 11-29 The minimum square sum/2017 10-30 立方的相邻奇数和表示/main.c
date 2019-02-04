#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,num,tem;
    while(scanf("%d",&n)!=EOF)
    {
        num=0;
        tem=n*n;
        for(i=0;;i++)
        {
            if((tem-i)%2!=0) num++;
            if(num==((n+1)/2)) break;
        }
        tem=tem-i;
        for(i=0;i<n;i++)
        {
            printf("%5d",tem+2*i);
        }
        printf("\n");



    }
    return 0;
}
