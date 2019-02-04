#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
return -(*(int *)b-*(int *)a);  //实现的是降序排序
}
int main()
{
    int numa,numb,i,j,flag;
    int a[110],b[110];
    while(scanf("%d%d",&numa,&numb)!=EOF)
    {
        flag=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        if(numa==0&&numb==0) break;
        for(i=0;i<numa;i++) scanf("%d",&a[i]);
        for(i=0;i<numb;i++) scanf("%d",&b[i]);
        for(i=0;i<numa;i++)
        {
            for(j=0;j<numb;j++)
            {
                if(a[i]==b[j]) a[i]=-1223333123;
            }
        }
        qsort(a,numa,sizeof(a[0]),cmp);
        for(i=0;i<numa;i++)
        {
            if((a[i]!=-1223333123))
            {
                printf("%d ",a[i]);
                flag++;
            }
        }
        if(flag==0) printf("NULL");
        printf("\n");

    }
    return 0;
}

