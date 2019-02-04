#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[10];
    int i,sum,lens,tem,CASE;
    scanf("%d",&CASE);
    getchar();
    while(CASE--)
    {
        gets(a);
        lens=strlen(a);
        sum=0;
        for(i=0;i<lens;i++)
        {
            if(a[i]<58&&a[i]>47) tem=a[i]-48;
            else if(a[i]>96&&a[i]<123) tem=a[i]-97+10;
            else if(a[i]>64&&a[i]<91) tem=a[i]-65+36;
            else if(a[i]=='#') tem=62;
            else if (a[i]='$') tem=63;
            sum=sum*64+tem;
        }
        printf("%d\n",sum);
    }
    return 0;
}
