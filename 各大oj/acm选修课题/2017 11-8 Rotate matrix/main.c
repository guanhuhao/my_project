#include <stdio.h>
#include <stdlib.h>
int a[1000][1000],b[1000][1000];
int main()
{
    int CASE,n,k,i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        k=k%4;
        if(k==3)
        {
            for(j=n-1;j>-1;j--)
            {
                for(i=0;i<n;i++)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
        }

        if(k==2)
        {
            for(i=n-1;i>-1;i--)
            {
                for(j=n-1;j>-1;j--)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
        }
        if(k==1)
        {
            for(j=0;j<n;j++)
            {
                for(i=n-1;i>-1;i--)
                    printf("%d ",a[i][j]);
                printf("\n");
            }
        }
        if(k==0)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    printf("%d",a[i][j]);
                printf("\n");
            }

        }
    }
    return 0;
}
