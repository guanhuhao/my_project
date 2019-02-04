#include <iostream>
#include <stdio.h>
using namespace std;
int a[5005];
int b[5005];
int main()
{
    int T,i,j,k,n,flag,ans;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        flag=0;ans=0;
        scanf("%d",&n);
        for(j=0;j<n;j++) scanf("%d",&a[j]);
        for(j=0;j<=a[0];j++)
        {
            b[0]=j;
            b[1]=a[0]-b[0];
            for(k=2;k<n;k++)
            {
                b[k]=a[k-1]-b[k-1]-b[k-2];
                if(b[k]<0){
                    flag=1;
                    break;
                }
            }
            if(!flag&&b[n-1]+b[n-2]==a[n-1]) ans++;
            flag=0;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
