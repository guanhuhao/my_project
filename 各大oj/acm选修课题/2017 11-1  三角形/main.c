#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M;
    float a,b,c,max;
    scanf("%d",&M);
    while(M--)
    {
        scanf("%f%f%f",&a,&b,&c);
        max=(a>b?a:b)>c?(a>b?a:b):c;
        if(max<a+b+c-max) printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}
