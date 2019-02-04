#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[1010][1010];
int main()
{
    char b[1010];
    int n,m,i,j,max,k,tem;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        max=0;
        memset(a,0,sizeof(a));
        if(n==0&&m==0) break;
        for(i=1;i<=n;i++)
        {
            scanf("%s",b);
            for(j=1;j<=m;j++)
            {
                if(b[j-1]=='@') a[i][j]=1;
            }
        }
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i-1][j]!=0&&a[i][j]!=0)
                {
                    a[i][j]=a[i][j]+a[i-1][j];
                    a[i-1][j]=0;
                    for(k=1;a[i-1][j+k]!=0;k++)
                    {
                        a[i][j]=a[i][j]+a[i-1][j+k];
                        a[i][j+k]=0;
                    }
                    for(k=1;a[i-1][j-k]!=0;k++)
                    {
                        a[i][j]=a[i][j]+a[i-1][j-k];
                        a[i][j-k]=0;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {

                if(a[i][j]!=0)
                {
                    tem=tem+a[i][j];
                    max=max>tem?max:tem;
                }
                else tem=0;
            }
        }
        printf("%d\n",max);

    }
    return 0;
}
