#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,lie,i,j;
    char a;
    while(scanf("%d %c",&N,&a)!=EOF)
    {
        lie=(N+1)/2;
        for(i=0;i<lie;i++)
        {
            for(j=0;j<N;j++)
                printf("%c",a);
            printf("\n");
        }

    }
    return 0;
}
