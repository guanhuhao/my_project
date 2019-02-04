#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ji[5],ou[5],i,j,tem;
    for(i=0;i<5;i++) scanf("%d%d",&ou[i],&ji[i]);
    for(i=0;i<5;i++)
    {
        for(j=i;j<5;j++)
        {
            if(ou[i]>ou[j])
            {
                tem=ou[i];
                ou[i]=ou[j];
                ou[j]=tem;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=i;j<5;j++)
        {
            if(ji[i]<ji[j])
            {
                tem=ji[i];
                ji[i]=ji[j];
                ji[j]=tem;
            }
        }
    }

    for(i=0;i<5;i++) printf("%d %d ",ou[i],ji[i]);
    printf("\n");

    return 0;
}
