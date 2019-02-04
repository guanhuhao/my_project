#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,flag=0;
    char a[100];
    while(gets(a)!=NULL)
    {
        for(i=0;i<(strlen(a)-1-i);i++)
        {
            if(a[i]!=a[strlen(a)-1-i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1) printf("NO\n");
        else printf("Yes\n");
        flag=0;
    }
    return 0;
}
