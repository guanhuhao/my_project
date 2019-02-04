#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i;
    char a[1200]={0};
    int num[10]={0};
    while(gets(a)!=NULL)
    {
        for(i=strlen(a);i--;)
        {
            num[a[i]-48]++;
        }
        for(i=-10;i++;)
        {
            if(num[i+9]!=0)
             {
                    printf("%d:%d\n",i+9,num[i+9]);
                    num[i+9]=0;
             }

        }
    }
    return 0;
}
