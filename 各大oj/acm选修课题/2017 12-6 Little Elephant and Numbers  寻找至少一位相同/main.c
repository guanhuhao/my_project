#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a[10];
    double tem2;
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
        tem2=sqrt(n);
        for(i=1; i<=tem2+0.00001; i++)
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
                tem=n/i;
                while(tem!=0&&n!=i*i)
                {
                    if(a[tem%10]==1)
                    {
                        count++;
                        //printf("%d\n",n/i);
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
