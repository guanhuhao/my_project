#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,baxi,deguo,agenting,helan;
    for(i=1234;i<4500;i++)
    {
        baxi=i/1000;
        deguo=(i/100)%10;
        agenting=(i/10)%10;
        helan=i%10;
        if((deguo==1)+(baxi==3)==1)
        {
            if( ( (agenting==2) + (helan==4) )==1)
            {
                if( ( (agenting==1) + (baxi==4) )==1)
                {
                    if( ( ( deguo==2 )+ (helan==3) )==1 )
                        printf("%d\n",i);
                }
            }
        }

    }
    return 0;
}
