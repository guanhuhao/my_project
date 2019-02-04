#include <stdio.h>

int a[1100000];
int main()
{
    int N,i,j;
    for(i=0;i<1100000;i++) a[i]=1;
    a[0]=a[1]=0;
    for(i=2;i<=1000000;i++)
    {
        for(j=2;i*j<1100000;j++)
            a[i*j]=0;
    }
    while(scanf("%d",&N)!=EOF)
    {
        i=3;
        if(N>=2) printf("2");
        while(i<=N)
        {
            if(a[i]!=0) printf(" %d",i);
            i++;
        }
        printf("\n");
    }
    return 0;
}
