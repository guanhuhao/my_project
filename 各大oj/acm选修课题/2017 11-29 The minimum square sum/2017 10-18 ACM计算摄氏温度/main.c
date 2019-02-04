#include <stdio.h>
#include <stdlib.h>

int main()
{
    int F;
    while(scanf("%d",&F) != EOF)
    {
        printf("Celsius = %.0d\n",5*(F-32)/9);
    }
    return 0;

}
