#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    while(scanf("%c%d",&T,&T)!=EOF)
    {
        T=T/10;
        printf("++++++++++++\n+");
        for(i=0;i<T;i++) printf("=");
        for(;i<10;i++) printf("~");
        printf("+-|\n+");
        for(i=0;i<T;i++) printf("=");
        for(;i<10;i++) printf("~");
        printf("+-|\n++++++++++++\n");
        getchar();
    }
    return 0;
}
