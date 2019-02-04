#include <stdio.h>
#include <stdlib.h>
int a[11][11];
int main()
{
    int N,i,j,tem,flag;
    while(scanf("%d",&N)!=EOF)
    {
        tem=1;
        flag=1;
        j=0;
        for(i=0;i<N;i++)
        {
            for(;j<N&&j>-1;j=j+flag)
            {
                a[i][j]=tem;
                tem++;
            }
            flag=-flag;
            if(j==N) j--;
            if(j==-1) j++;
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
