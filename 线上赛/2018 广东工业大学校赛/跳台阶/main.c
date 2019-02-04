#include <stdio.h>
#include <stdlib.h>
int a[35]={0};
int main()
{
    int T,n,i,j;

    for(i=1;i<=35;i++)
    {
        for(j=1;j<i;j++)
        {
            a[i]=a[i]+a[j];
        }
        a[i]++;
       // printf("%d\n",a[i]);
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
