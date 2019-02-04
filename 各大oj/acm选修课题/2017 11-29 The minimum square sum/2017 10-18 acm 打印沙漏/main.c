#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,i,j,k,q;
    char a;
    while(scanf("%d",&num)!=EOF)
    {
        getchar();
        a=getchar();
        if(num<7) printf("%c\n%d",a,num-1);
        else
        {
            num--;
            for(i=1; num>=i*4+2; i++)
            {
                num=num-i*4-2;
            }
            for(j=0; j<i; j++)
            {
                for(k=0; k<j; k++)
                {
                    printf(" ");
                }
                for(k=0; k<2*i-1-2*j; k++)
                    printf("%c",a);
                printf("\n");
            }
            for(j=0; j<i-1; j++)
            {
                for(k=0; k<i-j-2; k++) printf(" ");
                for(k=0; k<j*2+3; k++) printf("%c",a);
                printf("\n");
            }
            printf("%d\n",num);
        }
    }
    return 0;
}
