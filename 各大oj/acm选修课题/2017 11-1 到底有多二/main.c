#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[60];
    int i,lens;
    float flag2,flag=0,geshu;
    while(gets(a)!=NULL)
    {
        geshu=0;
        flag=1;
        flag2=1;
        lens=strlen(a);
        for(i=0;i<lens;i++)
        {
            if(a[i]=='2') geshu++;
        }
        if((a[lens-1]-48)%2==0) flag=2;
        if(a[0]=='-')
         {
                lens--;
                flag2=1.5;
         }

        printf("%.2f%%\n",(((float)geshu/(float)lens)*flag*flag2*(float)100));
    }

    return 0;
}
