#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,num,CASE,count;
    char a[500];
    scanf("%d",&CASE);
    getchar();
    while(CASE--)
    {
        count=0;
        gets(a);
        num=strlen(a);
        for(i=0;i<num;i++)
            if(a[i]<0)  count++;
        printf("%d\n",count/2);
    }
    return 0;
}
