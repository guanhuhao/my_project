#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a[10][10],i,j,N,tem;
    while(scanf("%d",&N)!=EOF)
    {
        i=0;
        j=0;
        tem=1;
        memset(a,0,sizeof(a));
        a[0][0]=1;
        while(tem!=N*N)
        {
            while(j+1<N&&a[i][j+1]==0) {tem++; a[i][j+1]=tem; j++;}
            while(i+1<N&&a[i+1][j]==0) {tem++; a[i+1][j]=tem; i++;}
            while(j-1>-1&&a[i][j-1]==0) {tem++; a[i][j-1]=tem; j--;}
            while(i-1>-1&&a[i-1][j]==0) {tem++;a[i-1][j]=tem;i--;}
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
