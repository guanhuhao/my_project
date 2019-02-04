#include <stdio.h>
#include <stdlib.h>
int huisu(int a)
{
    if(a%2==0) return a/2;
    else return (a-1)/2;
}
int main()
{
    int a,b,N,i,tem;
    int numa,numb;
    while(scanf("%d",&N)!=EOF)
    {
        while(N--)
        {

            scanf("%d%d",&a,&b);
            tem=a;
            for(i=0;tem!=0;i++)
                tem=tem/2;
            numa=i;
            tem=b;
            for(i=0;tem!=0;i++)           // printf("1");
                tem=tem/2;
            numb=i;
            while(a!=b)
            {
                if(a>b) a=huisu(a);
                else b=huisu(b);
            }
            for(i=0;a!=0;i++) a=a/2;
            printf("%d\n",numa+numb-i*2);
        }
    }
    return 0;

}
