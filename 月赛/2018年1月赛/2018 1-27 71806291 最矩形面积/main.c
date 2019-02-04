#include <stdio.h>
#include <stdlib.h>
int max(int a,int b ,int c)
{
    return ((a>b?a:b)>c?(a>b?a:b):c);
}
int min(int a,int b ,int c)
{
    return ((a<b?a:b)<c?(a<b?a:b):c);
}
int main()
{
    int T;
    long long x1,x2,x3,y1,y2,y3;
    long long minx,miny,maxx,maxy;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
        minx=min(x1,x2,x3);
        miny=min(y1,y2,y3);
        maxx=max(x1,x2,x3);
        maxy=max(y1,y2,y3);
        printf("%lld\n",(maxx-minx)*(maxy-miny));
    }
    return 0;
}
