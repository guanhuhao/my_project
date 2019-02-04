#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,numji,numou,i;
    int tem[1100];
    while(scanf("%d",&N)!=EOF)
    {
        numou=numji=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&tem[i]);
            if(tem[i]%2==0) numou++;
            else numji++;
        }
        printf("%d %d\n",numji,numou);
    }
    return 0;

}
