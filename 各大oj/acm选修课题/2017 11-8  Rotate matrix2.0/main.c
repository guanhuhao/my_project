#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1100][1100],b[1100][1100];
int main()
{
    int n,k,i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        k=k%4;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }

        while(k--)
        {

            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    b[j][n-1-i]=a[i][j];
            }

            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                    a[i][j]=b[i][j];
            }

        }


        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }

    }
    return 0;
}
