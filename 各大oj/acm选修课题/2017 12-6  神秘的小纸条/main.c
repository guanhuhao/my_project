#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int  T,i,j,lena,lenb,count;
    char a[110],b[110];
    char tema[110],temb[110];
    while(scanf("%d",&T)!=EOF)
    {
        memset(tema,0,sizeof(tema));
        memset(temb,0,sizeof(temb));
        count=1;
        scanf("%s%s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lena;i++)
        {
            if(tema[i]!=0) continue ;
            tema[i]=count;
            for(j=i;j<lena;j++)
            {
                if(a[j]==a[i]) tema[j]=count;
            }
            count++;

        }
        count=1;
        for(i=0;i<lenb;i++)
        {
            if(temb[i]!=0) continue ;
            temb[i]=count;
            for(j=i;j<lenb;j++)
            {
                if(b[j]==b[i]) temb[j]=count;
            }
            count++;
        }
        if(strcmp(tema,temb)==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
