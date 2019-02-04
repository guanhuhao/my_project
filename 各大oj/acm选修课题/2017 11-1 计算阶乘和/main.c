#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,sum,i,j,tem;
    while(scanf("%d",&N)!=EOF)
    {
        sum=0;
        for(i=1;i<=N;i++)
        {
            tem=1;
            for(j=2;j<=i;j++)
            {
               tem=tem*j;
            }
            sum=sum+tem;
            tem=1;
        }
        printf("%d\n",sum);
    }
    return 0;
}
