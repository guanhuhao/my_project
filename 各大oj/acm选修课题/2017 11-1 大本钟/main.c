#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,min,ci,i;
    //char h1,h2,m1,m2;
    //while(scanf("%c%c:%c%c",&h1,&h2,&m1,&m2)!=EOF)
    while(scanf("%d:%d",&h,&min)!=EOF)
    {
        ci=0;
        //h=(h1-48)*10+(h2-48);
        //min=(m1-48)*10+(m2-48);
        ci=h-12;
        if(min!=0) ci++;
        //if((h<12&&h>=0)||(h==12&&min==00)) printf("Only %c%c:%c%c.  Too early to Dang.",h1,h2,m1,m2);
        if((h<12&&h>=0)||(h==12&&min==00)) printf("Only %02d:%#2d.  Too early to Dang.",h,min);
        else
            for(i=0;i<ci;i++)
            {
                printf("Dang");
            }
        printf("\n");
      //  getchar();
    }
    return 0;
}
