#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int CASE,i,num,flag;
    char a[110];
    scanf("%d",&CASE);
    getchar();
    while(CASE--)
    {
        flag=0;
        scanf("%s",a);
        num=strlen(a);
        for(i=0;i<=(num+1)/2;i++)
        {
            if( a[i] != a[num-1-i] )
            {
                flag=1;
                break;
            }
        }
        if(flag==1) printf("no\n");
        if(flag==0) printf("yes\n");
    }

    return 0;
}
