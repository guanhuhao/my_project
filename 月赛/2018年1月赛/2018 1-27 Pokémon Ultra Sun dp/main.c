#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double dp[3030][3030];
int T,h1,h2,w;
double p;
double myfun(int a,int b)
{
    if(a==0||b==0) return 0;
    if(dp[a][b]==0) dp[a][b]=(myfun(a-1,b)+1)*(1-p)+(myfun(a,b-1)+1)*p;
    return dp[a][b];
}
int init()
{
    int i,j;
    for(i=0;i<3030;i++)
        for(j=0;j<3030;j++)
            dp[i][j]=0;
    return 0;
}
int main()
{

    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d%d%lf",&h1,&h2,&w,&p);
        h1=h1/w+(h1%w==0?0:1);
        h2=h2/w+(h2%w==0?0:1);
        printf("%.6lf\n",myfun(h1,h2));
    }
    return 0;
}
