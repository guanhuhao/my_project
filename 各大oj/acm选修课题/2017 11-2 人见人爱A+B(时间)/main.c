#include <stdio.h>
#include <stdlib.h>

int main()
{
    int AH,AM,AS,BH,BM,BS,outh,outmin,outs,CASE;
    scanf("%d",&CASE);
    while(CASE--)
    {
        scanf("%d%d%d%d%d%d",&AH,&AM,&AS,&BH,&BM,&BS);
        outh=AH+BH;
        outmin=AM+BM;
        outs=AS+BS;
        if(outs>59)
        {
            outs=outs-60;
            outmin++;
        }
        if(outmin>59)
        {
            outmin=outmin-60;
            outh++;
        }
        printf("%d %d %d\n",outh,outmin,outs);
    }
    return 0;
}
