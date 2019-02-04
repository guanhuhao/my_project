#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int c[4100000] ;
int biao[2100000];

int main()
{
    int a[2100],b[2100],N,i,count,j,k=0;
    while(scanf("%d",&N)!=EOF)
    {
        memset(biao,0,sizeof(biao));
        count=0;
        k=0;

        for(i=0;i<N;i++) {scanf("%d",&a[i]);biao[a[i]]=1;}
        for(i=0;i<N;i++) {scanf("%d",&b[i]);biao[b[i]]=1;}

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                c[k]=a[i]^b[j];
                if(biao[c[k]]==1) count++;
            }
        }



        if(count%2==0) printf("Karen\n");
        else printf("Koyomi\n");
    }
    return 0;
}
