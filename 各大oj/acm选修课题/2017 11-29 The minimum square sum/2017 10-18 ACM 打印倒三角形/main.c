#include <stdio.h>
int main()
{
    int i=0,j=0,n;

    while(scanf("%d",&n)!=EOF)
   {
    n=2*n-1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++) printf(" ");
        for(j=0;j<n-2*i;j++) printf("*");
        printf("\n");
    }
   }

    return 0;

}
