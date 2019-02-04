#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int biao[100010],biao2[100010];
int T,n,k;
int init()
{
    memset(biao,0,sizeof(biao[0]));
    memset(biao2,0,sizeof(biao2[0]));
    return 0;
}
int shuru()
{
    int i,tem,j=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tem);
        if(biao2[tem]==0) biao2[tem]=j++;
        biao[biao2[tem]]++;
    }
    //for(i=0;i<n;i++) printf("%d  ",biao[i]);
    return 0;
}
bool cmp(int a,int b)
{
    return a>b;
}
/*int solve()
{
    int ans=0,i;
    while(1){
        sort(biao,biao+n,cmp);
        if(biao[k-1]==0) break;
        //printf("%d\n",biao[k-1]);

        ans=ans+biao[k-1]-biao[k]+(biao[k]==0?0:1);
        printf("%d\n",ans);
        for(i=0;i<k;i++) biao[i]=biao[i]-(biao[k-1]-biao[k])-(biao[k]==0?0:1);
    }
    return ans;
}*/
int main()
{
    int t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        shuru();
        printf("Case #%d:\n%d\n",t,solve());
    }
    return 0;
}
