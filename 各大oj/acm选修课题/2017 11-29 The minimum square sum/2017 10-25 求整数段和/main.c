#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,i,sum;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        sum=0;
        for(i=0;i<(b-a)+1;i++)
        {
            if(i%5==0 && i!=0) printf("\n");
            printf("%5d ",a+i);
            sum=sum+a+i;
        }
        printf("\n");
        printf("Sum = %d",sum);

    }
    return 0;
}
