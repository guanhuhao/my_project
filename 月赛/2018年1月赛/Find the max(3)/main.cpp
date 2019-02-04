#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> q;
int biao[100010],biao2[100010];
int a[100010];
int T,n,k;
int init()
{
    int i;
    for(i=0;i<100010;i++) biao[i]=0;
    for(i=0;i<100010;i++) biao2[i]=-1;
    return 0;
}
int shuru()
{
    int i,tem,j=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&tem);
        if(biao2[tem]==-1) biao2[tem]=j++;
        biao[biao2[tem]]++;
    }
    for(i=0;biao[i]!=0;i++) q.push(biao[i]);
    //for(i=0;i<n;i++) printf("%d  ",biao[i]);
    return 0;
}

int solve()
{
    int ans,flag,i;
    ans=0;
    flag=1;
    while(1)
    {
        for(i=0;i<k;i++)
        {           // printf("%d\n",q.top());
            if(q.top()==0) {flag=0;break;}

            a[i]=q.top()-1;
            q.pop();
        }
        if(flag==0) break;
        ans++;
        for(i=0;i<k;i++) q.push(a[i]);
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        init();
        shuru();
        printf("Case #%d:\n%d\n",t,solve());
    }
    return 0;
}
