#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,m,CASE;
    scanf("%d",&CASE);
    while(CASE--)
    {
        m=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            m=m+i*4+1;
        }
        printf("%d\n",m);;
    }
    return 0;
}
