#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long a[110][110];
int init()
{
    int i,j;
    memset(a,0,sizeof(a));
    a[0][0]=1;
    for(i=1;i<110;i++)
    {
        for(j=1;j<=i;j++)
            {a[i][j]=(j*a[i-1][j]+a[i-1][j-1])%1000000007;}
    }
    return 0;
}
int main()
{
    int n,m,i;
    long long ans;
    init();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans=a[n][m];
        for(i=1;i<=m;i++)
        {
            ans=ans*i%1000000007;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
