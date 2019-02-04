#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,max,mid,min;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        max=(a>b?a:b)>c?(a>b?a:b):c;
        min=(a<b?a:b)<c?(a<b?a:b):c;
        mid=a+b+c-min-max;
        printf("%d->%d->%d\n",min,mid,max);
    }
    return 0;

}
