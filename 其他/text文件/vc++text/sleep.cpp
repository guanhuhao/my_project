#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[10];
    int n,i,count,tem;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        count=0;
        tem=n;
        while(tem!=0)
        {
            a[tem%10]=1;
            tem=tem/10;
        }

        for(i=1; i<=n; i++)
        {
            if(n%i==0)
            {
                tem=i;
                while(tem!=0)
                {
                    if(a[tem%10]==1)
                    {
                        count++;
                       // printf("%d\n",i);
                        break;
                    }
                    tem=tem/10;
                }
            }

        }
        printf("%d\n",count);
    }
    return 0;
}