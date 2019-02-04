#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int flag=0;
    long a=0,b=0,tem,i,j;
    scanf("%ld%ld",&a,&b);
    for(i=a;i<=b;i++)
    {
        char A[10]={0};
        flag=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            tem=i;
            for(j=0;tem!=0;tem/=10,j++) A[j]=tem%10+48;
            tem=j;

            for(j=0;j<tem;j++)
            {
                if(A[j]!=A[tem-1-j])
                {
                    flag=2;
                    break;
                }
            }
            if(flag!=2) printf("%ld\n",i);
        }
    }
    return 0;
}
