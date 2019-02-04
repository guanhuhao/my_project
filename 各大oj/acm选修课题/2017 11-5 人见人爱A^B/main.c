#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,mul,i;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0&b==0) break;
        mul=1;
        for(i=0;i<b;i++)
        {
            mul=mul*a;
            mul=mul%1000;
        }
        printf("%d\n",mul);
    }
    return 0;
}
