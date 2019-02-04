#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp ( const void *a , const void *b )

{

  return *(int *)a - *(int *)b;  //ÉıĞòÅÅĞò

}
int main()
{
    char a[25];
    int b[25],i,lens,k;
    while(gets(a)!=NULL)
    {
        lens=strlen(a);
        k=0;
        for(i=0;i<lens;i++)
        {
            if(a[i]>47&&a[i]<58)
            {
                b[k++]=a[i]-48;
            }
        }
        qsort(b,k,sizeof(b[0]),cmp);
        for(i=0;i<k;i++) printf("%d",b[i]);
        printf("\n");
    }
    return 0;
}
