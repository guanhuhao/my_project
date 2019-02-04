#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100000];
int main()
{
    int T,i,N;
    memset(a,0,sizeof(a));
    a[0]=0;
    a[1]=1;
    for(i=2;i<100000;i++) a[i]=a[i-1]+i-1;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            scanf("%d",&N);
            i=1;
            while(N>a[i]) i++;
            printf("%d\n",i-1);
        }
    }
    return 0;
}
