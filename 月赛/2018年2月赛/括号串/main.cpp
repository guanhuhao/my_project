#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int T,i,j,len,tem=0;
    long long ans;
    char a[5005];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        ans=0;
        scanf("%s",a);
        len=strlen(a);
        for(j=0;j<len;j++)
        {
            if(a[j]-a[j+1]==-1)
            {
                for(;j<len;j=j+2)
                {
                    if(a[j]+1!=a[j+1]) break;
                    tem++;
                }
                ans=ans+tem*(tem+1)/2;
                len=len-2*tem;
                 for(;j<len;j++)
                {
                    a[j]=a[j+tem*2];
                    a[j+1]=a[j+1+tem*2];
                }
                j=-1;
                tem=0;
               /* ans++;
                len=len-2;
                for(;j<len;j++)
                {
                    a[j]=a[j+2];
                    a[j+1]=a[j+3];
                }
                //puts(a);
                j=-1;*/
            }
        }
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
