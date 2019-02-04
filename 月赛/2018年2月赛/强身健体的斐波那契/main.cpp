#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[100005][45]={0};
int base[100005];
int init()
{
    int i,j;
    a[0][44]=a[1][44]=1;
    for(i=2;i<100002;i++)
    {
        for(j=0;j<44;j++) a[i][j]=a[i-1][j]+a[i-2][j];
        for(j=42;j>-1;j++)
        {
            a[i][j+1]=a[i][j+1]+a[i][j]/10;
            a[i][j]=a[i][j]%10;
        }
    }
}
int main()
{
    int T,i,j;
    scanf("%d",&T);
    init();
    for(i=1;i<=T;i++)
    {
        scanf("")
    }
}
