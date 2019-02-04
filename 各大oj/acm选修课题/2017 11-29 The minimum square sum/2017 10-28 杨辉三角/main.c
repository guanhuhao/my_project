#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[35][35],i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            a[i][0]=1;
            a[i][i]=1;
        }
        for(i=2;i<n;i++)
        {
            for(j=1;j<i;j++)
                a[i][j]=a[i-1][j]+a[i-1][j-1];
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<i+1;j++)
            {
                if(j==0) printf("%d",a[i][0]);
                else printf(" %d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;

}
