#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define small 0.00001
int main()
{
    int x1,x2,y1,y2,x0,y0,r,c;
    double l;
    while(scanf("%d%d%d",&x0,&y0,&r)!=EOF)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        c=(x1-x2)*y1-(y1-y2)*x1;
        l=(double)abs((x1-x2)*y0-(y1-y2)*x0-c)/sqrt((double)pow(x1-x2,2)+pow(y1-y2,2));
        if(l<r-small) printf("2\n");
        if(l>r-small&&l<r+small) printf("1\n");
        if(l>r+small) printf("0\n");
    }
    return 0;

}
