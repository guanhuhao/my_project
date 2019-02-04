#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int biao[110000];
int main()
{
    int N,M,i,j,flag,tem;
    while(scanf("%d",&N)!=EOF)
    {
        memset(biao,0,sizeof(biao));
        flag=0;

        for(i=0; i<N; i++)
        {
            scanf("%d",&M);
            for(j=0; j<M; j++)
            {
                scanf("%d",&tem);
                if(M>1) biao[tem]=1;
            }
        }
        scanf("%d",&M);
        for(i=0; i<M; i++)
        {
            scanf("%d",&tem);
            if(biao[tem]==0)
            {
                if(flag==0)
                {
                    printf("%05d",tem);
                    flag=1;
                    biao[tem]=1;
                }
                else
                {
                    printf(" %05d",tem);
                    biao[tem]=1;
                }
            }
        }
        if(flag==0) printf("No one is handsome");
        printf("\n");
    }
    return 0;
}
