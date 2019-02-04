#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    while(scanf("%d",&N)!=EOF)
    {
        printf("%d",N);
        for(i=1;i<=N-1;i++) printf(" %d",i);
        printf("\n");
    }
    return 0;
}
