#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,a,i,mul;
    while(scanf("%d",&N)!=EOF)
    {
        while(N--)
        {
            mul=1;
            scanf("%d",&a);
            for(i=1;i<=a;i++)
                mul=mul*i;
            printf("%d\n",mul);
        }
    }
    return 0;
}
