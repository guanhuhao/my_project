#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag=0,i,j;
    char a[28];
    while(scanf("%s",a)!=EOF)
    {
        flag=0;
        for(i=0;i<27;i++)
        {
            for(j=i+1;j<27;j++)
            {
                if(a[i]==a[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if((j-i)==1)    printf("No\n");
        else  printf("Yes\n");
    }
    return 0;
}
