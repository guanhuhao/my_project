#include <stdio.h>
#include <stdlib.h>

int main()
{
    double H;
    while(scanf("%lf",&H)!=EOF)
    {
        printf("%.1lf\n",(H-100)*1.8);
    }
   return 0;
}
