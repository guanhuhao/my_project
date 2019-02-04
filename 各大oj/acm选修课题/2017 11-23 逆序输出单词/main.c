#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1000][30];
int main()
{
    int i=0,j=0,k=0;
    char b[1000];
    gets(b);
    for(i=0;i<strlen(b);i++)
    {
        if(b[i]==' ') {j++;k=0;i++;}
        a[j][k]=b[i];
        k++;
    }
    for(;j>-1;j--) printf("%s\n",a[j]);
    return 0;
}
