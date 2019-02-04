#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fu[1000];
    long long i,lens,sum,tem,flag;
    long long shu[1000];
    while(scanf("%lld%c",&shu[0],&fu[0])!=EOF)
    {
        i=0;
        while(fu[i]=='-'||fu[i]=='+'||fu[i]=='*'||fu[i]=='/') { i++; scanf("%lld%c",&shu[i],&fu[i]);}

        lens=i;
        i=0;
        flag=1;
        sum=0;
        while(i<=lens)
        {
            tem=shu[i];
            while(fu[i]=='*'||fu[i]=='/')
            {
                if(fu[i]=='*') tem=tem*shu[i+1];
                if(fu[i]=='/') tem=tem/shu[i+1];
                i++;
            }
            sum=sum+flag*tem;
            if(fu[i]=='-') flag=-1;
            if(fu[i]=='+') flag = 1;
            i++;
        }

        printf("%lld\n",sum);
        memset(fu,0,sizeof(fu));
        memset(shu,0,sizeof(shu));

    }
    return 0;
}
