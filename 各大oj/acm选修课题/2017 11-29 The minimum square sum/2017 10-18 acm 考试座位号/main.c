#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i,num,b[1000],c[1000],d[1000],j;
    char a[1000][15];
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0; i<N; i++)
        {
            scanf("%s",a[i]);
            scanf("%d%d",&b[i],&c[i]);
        }
        scanf("%d",&num);
        for(i=0; i<num; i++)  scanf("%d",&d[i]);
        for(i=0; i<num; i++)
        {
            for(j=0; j<N; j++)
            {
                if(b[j]==d[i])
                {
                    printf("%s %d\n",a[j],c[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
