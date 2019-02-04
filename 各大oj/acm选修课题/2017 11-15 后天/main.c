#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day;
    while(scanf("%d",&day)!=EOF)
    {
        printf("%d\n",(day+2)%8+(day+2)/8);
    }
    return 0;
}
