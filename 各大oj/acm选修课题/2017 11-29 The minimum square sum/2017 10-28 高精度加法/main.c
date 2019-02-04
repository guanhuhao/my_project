#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,CASE,lens;
    char a[1100],b[1100],tem1[1100],tem2[1100];
    scanf("%d",&CASE);
    for(i=0;i<CASE;i++)
    {
        memset(tem1,0,sizeof(tem1));
        memset(tem2,0,sizeof(tem2));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));                    //重置数组99


        scanf("%s",tem1);
        lens=strlen(tem1);
        for(j=0;j<lens;j++)     a[1100-j-1]=tem1[lens-1-j];
        scanf("%s",tem2);
        lens=strlen(tem2);
        for(j=0;j<lens;j++)    b[1100-j-1]=tem2[lens-1-j];             //完成输入  同时使数字从数组角标从高到低排序

        for(j=0;j<1100;j++)
        {
           if( a[1100-j-1]!=0&&b[1100-j-1]!=0) a[1100-j-1]=a[1100-j-1]+b[1100-j-1]-48;    //完成相加
           else if(a[1100-j-1]!=0||b[1100-j-1]!=0) a[1100-j-1]=a[1100-j-1]+b[1100-j-1];
        }
        for(j=0;j<1100;j++)                                          //进位
        {
            a[1100-j-2]=a[1100-j-2]+a[1100-j-1]/58;
            a[1100-j-1]=a[1100-j-1]-10*(a[1100-j-1]/58);
        }

        for(j=0;a[j]==0;j++);
        if(a[j]==1) a[j]=a[j]+48;
        printf("Case %d:\n%s + %s = ",i+1,tem1,tem2);
        for(;j<1100;j++)        printf("%c",a[j]);
        if(i!=CASE-1) printf("\n\n");
        else printf("\n");
    }
    return 0;
}
