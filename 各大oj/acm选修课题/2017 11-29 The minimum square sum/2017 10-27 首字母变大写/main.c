#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num;
    char a[500];
    while(gets(a)!=NULL)
    {
        num=strlen(a);
        for(i=0;i<num;i++)
        {
            if((a[i-1]==' '&&a[i]!=' ') || i==0) printf("%c",a[i]-32);
            else printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
