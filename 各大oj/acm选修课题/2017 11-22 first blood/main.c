#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,i;
    char a[1000];
    while(scanf("%s",a)!=EOF)
    {
        count=0;
        for(i=0;a[i]!='\0';i++) if(a[i]=='F') count++;
        printf("%d\n",count);
    }
    return 0;
}
