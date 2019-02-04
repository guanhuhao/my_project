#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,numa,numb,flag=0;
    char a[11000],b[11000];
    while(gets(a)!=NULL)
    {
        gets(b);
        numa=strlen(a);
        numb=strlen(b);
        for(i=0;i<numa;i++)
        {
            for(j=0;j<numb;j++)
            {
                if(a[i]==b[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=1) printf("%c",a[i]);
            flag=0;
        }
        printf("\n");
    }
    return 0;
}
