#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[11000];
int main()
{
    int numg,nump,numl,numt;
    int i,lens;
    while(gets(a)!=NULL)
    {
        numg=nump=numl=numt=0;
        lens=strlen(a);
        for(i=0;i<lens;i++)
        {
            if(a[i]=='g'||a[i]=='G') numg++;
            if(a[i]=='p'||a[i]=='P') nump++;
            if(a[i]=='l'||a[i]=='L') numl++;
            if(a[i]=='t'||a[i]=='T') numt++;
        }

        while(numg!=0||nump!=0||numl!=0||numt!=0)
        {
            if(numg!=0) {printf("G");numg--;}
            if(nump!=0) {printf("P");nump--;}
            if(numl!=0) {printf("L");numl--;}
            if(numt!=0) {printf("T");numt--;}
        }
        printf("\n");
    }
    return 0;
}
