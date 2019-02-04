#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j;
    char a[200],tem;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        for(j=i+1;j<strlen(a);j++)
        {
            if(a[i]>a[j])
            {
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }

        }
    }
    printf("%s\n",a);
    return 0;

}
