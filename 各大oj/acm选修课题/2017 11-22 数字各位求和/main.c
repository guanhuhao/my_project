#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[110];
    int i,sum;
    while(scanf("%s",a)!=EOF)
    {
        sum=0;
        i=0;
        while(a[i]<58&&a[i]>47) sum=sum+a[i++]-48;
        printf("%d\n",sum);
    }
    return 0;
}
