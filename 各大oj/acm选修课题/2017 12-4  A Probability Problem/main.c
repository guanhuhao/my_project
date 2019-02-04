#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,j,ci;
    double y,ans,tem,C;
    while(scanf("%d%d",&k,&n)!=EOF)
    {
        scanf("%lf",&y);
        tem=1;
        ans=0;
        if(y<0.000001||y>0.999999) {printf("0.00\n");continue;}
        for(i=0;i<n;i++)
            tem=tem*(1-y);
        ans=tem;
        ci=n-k;
        for(i=0;i<ci;i++)
        {
            C=1;
            for(j=n;j>k;j--)
            {
                C=C*j;
            }
            for(j=1;j<=(n-k);j++)
            {
                C=C/j;
            }
            ans=ans+C*tem;
            tem=(tem/(1-y))*y;
            k--;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
