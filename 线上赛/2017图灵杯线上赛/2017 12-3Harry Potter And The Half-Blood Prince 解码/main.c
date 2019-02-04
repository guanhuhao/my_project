#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1010];
int main()
{
    int k,b,i,lens;
    while(scanf("%d%d",&k,&b)!=EOF)
    {
        gets(a);

        lens=strlen(a);
        for(i=0;i<lens;i++)
        {
            if(a[i]<=90&&a[i]>=65)
            {
                printf("%c",((a[i]-65)*k+b)%26+65);
            }
            else if(a[i]>=97&&a[i]<=122)
            {
                printf("%c",((a[i]-97)*k+b)%26+97);
            }
            else printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
