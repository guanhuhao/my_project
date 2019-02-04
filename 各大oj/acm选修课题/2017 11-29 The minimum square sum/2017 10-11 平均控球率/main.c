#include <stdio.h>
#include <stdlib.h>

int main()
{
    double sum=0,a;
    int i=0;
    while(scanf("%lf%%",&a)!=EOF)
    {
        sum=sum+a/100;
        i++;
    }
    printf("%.4lf",sum/i);
    return 0;
}
