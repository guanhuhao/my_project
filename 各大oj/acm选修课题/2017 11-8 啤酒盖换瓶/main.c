#include <stdio.h>
#include <stdlib.h>

int main()
{
    int CASE,money,gaizi,pingzi,sum,tem;
    scanf("%d",&CASE);
    while(CASE--)
    {
        sum=0;
        scanf("%d",&money);
        sum=money/2;
        pingzi=sum;
        gaizi=sum;
        while(pingzi>=2||gaizi>=4)
        {
            tem=pingzi/2+gaizi/4;
            sum=sum+tem;
            pingzi=pingzi%2+tem;
            gaizi=gaizi%4+tem;

}
        printf("%d\n",sum);
    }
    return 0;
}
