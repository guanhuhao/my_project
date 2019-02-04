#include <stdio.h>
#include <stdlib.h>
double solve(int num,double r1,double r2,int deep)
{
    if(num==0) return 1;
    if(deep>2) return 0;
    double ans=0,base=1;
    int i,j;
    for(i=0;i<=num;i++)
    {
        for(j=0;j<i;j++)    base=base*r1;
        for(;j<num;j++)     base=base*r2;
        ans=ans+base*solve(2*i,r1,r2,deep+1);
        base=1;
        //printf("%lf\n",ans);
    }
    return ans;
}
double solve2(int num,double r1,double r2,int deep)
{
    int i;
    double ans,base;
    if(deep>20) return 0;
    for(base=1,i=0;i<num;i++) base=base*r2;
    ans=base;
    for(base=1,i=0;i<num;i++) base=base*r1;
    ans=ans+base*solve2(num*2,r1,r2,deep+1);
    //  printf("%lf\n",ans);
    return ans;

}
double solve3(double r1,double r2)
{
    if(r2<=0.00000001) return 1;
    int i;
    double base=r2,ans=0;
    for(i=0;i<1000;i++)
    {
        ans=ans+base;
        base=base*base*r1;
    }
    return ans;
}
int main()
{
    int T;
    double rr,rl;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&rr,&rl);
        //printf("%.3lf\n",solve2(1,rr*rl,(1-rr)*(1-rl),1));
        printf("%.3lf\n",solve3(rr*rl,(1-rr)*(1-rl)));
    }
    return 0;
}
