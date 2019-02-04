#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int a[N][N];
int main()
{
    int step=0,i=0,j=N-1;
    memset(a,0,sizeof(a));
    a[0][N-1]=step=1;
    //printf("1");
    while(step<N*N)
    {
       // printf("1");
        while(i<N-1 && a[i+1][j]==0 ) {step++;a[i+1][j]=step;i++;}
        while(j>0 && a[j][j-1] == 0) {step++;a[i][j-1]=step;j--;}
        while(i>0 && a[i-1][j] == 0) {step++;a[i-1][j]=step;i--;}
        while(j<N-1 &&a[i][j+1] == 0) {step++;a[i][j+1]=step;j++;}

    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;

}
