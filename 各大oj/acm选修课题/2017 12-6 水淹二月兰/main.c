#include <stdio.h>
#include <stdlib.h>
int T,n,m,i,j,temi,temj,count;
char a[110][110];
int finds()
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i][j]=='S')
            {
                temi=i;
                temj=j;
                return 0;
            }
        }
    }
    return 1;
}

int kuozhang()
{
    i=1;
    while(temi+i<n&&a[temi+i][temj]!='#')
    {
        if(a[temi+i][temj]=='*')
        {
            count++;
            a[temi+i][temj]='S';
        }
        i++;
    }
    i=1;
    while(temi-i>-1&&a[temi-i][temj]!='#')
    {
        if(a[temi-i][temj]=='*')
        {
            count++;
            a[temi-i][temj]='S';
        }
        i++;
    }
    j=1;
    while(temj+j<m&&a[temi][temj+j]!='#')
    {
        if(a[temi][temj+j]=='*')
        {
            count++;
            a[temi][temj+j]='S';
        }
        j++;
    }
    j=1;
    while(temj-j>-1&&a[temi][temj-j]!='#')
    {
        if(a[temi][temj-j]=='*')
        {
            count++;
            a[temi][temj-j]='S';
        }
        j++;
    }
    a[temi][temj]='0';
    return 0;
}
int main()
{
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            count=0;
            scanf("%d%d",&n,&m);
            for(i=0; i<n; i++)
            {
                scanf("%s",a[i]);
            }
            while(finds()!=1)
            {
                //printf("%d  %d\n",temi,temj);
                kuozhang();
            }

            //printf("%d  %d  %d\n",finds(),temi,temj);
            printf("%d\n",count);
           // for(i=0;i<n;i++) printf("%s\n",a[i]);
        }

    }
    return 0;
}
