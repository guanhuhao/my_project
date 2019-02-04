#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int N,i,j,k;
int head,tail,q[100010];
double sum[100010],dp[100010];
double a,b,c;
double fenzi(int n,int m)
{
    return dp[n]+a*sum[n]/4-b*sum[n]/2-(dp[m]+a*sum[m]/4-b*sum[m]/2);
}

double fenmu(int n,int m)
{
    return (sum[n]-sum[k])*a/2;
}

double getdp(int n, int m)
{
    return dp[m]+a*(sum[n]-sum[m])*(sum[n]-sum[m])/4+(sum[n]-sum[m])*b/2+c;
}

int main()
{

    while(scanf("%d",&N)!=EOF)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        for(i=1;i<=N;i++)    scanf("%lf",&sum[i]);
        sum[0]=dp[0]=0;
        sort(sum,sum+N+1);
        for(i=N;i>0;i--) sum[i]=sum[i]-sum[1];
        head=tail=0;
        q[tail++]=0;
        for(i=1;i<=N;i++)
        {
            printf("%d  %d\n",head,tail);
            while(head+1<tail&&fenzi(q[head+1],q[head])<=fenmu(q[head+1],q[head])*sum[i])
                head++;
            dp[i]=getdp(i,q[head]);
            printf("%lf\n",dp[i]);
            printf("%d  %d\n",head,tail);
            while(head+1<tail&&fenzi(i,q[tail-1])*fenmu(q[tail-1],q[tail-2])<=fenzi(q[tail-1],q[tail-2])*fenmu(i,q[tail-1]))
                tail--;
            q[tail++]=i;
            printf("%d  %d  %d\n",i,head,tail);
            for(j=0;j<5;j++) printf("%d ",q[j]);
            printf("\n");

        }


    }
    return 0;
}
