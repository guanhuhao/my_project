#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[500]={0},b[500]={0};
    int i,pointa,pointb,tem,flag,flag2,flag3;
    while(scanf("%s%s",a,b)!=EOF)
    {
        flag2=flag3=tem=0;
        for(i=0;i<500;i++)  {if(a[i]=='.') {pointa=i;flag2=1; break;}}
        for(i=0;i<500;i++)  {if(b[i]=='.') {pointb=i;flag3=1; break;}}
        if(flag2==0)        {for(i=499;i>-1;i--) {if(a[i]!=0) {pointa=i+1;a[i+1]='.';break;}}}
        if(flag3==0)        {for(i=499;i>-1;i--) {if(b[i]!=0) {pointb=i+1;b[i+1]='.';break;}}}
        flag=pointa>=pointb?1:0;

        for(i=1;flag==1&&pointb-i>-1;i++) {a[pointa-i]=a[pointa-i]+b[pointb-i];}
        for(i=1;flag==0&&pointa-i>-1;i++) {b[pointb-i]=a[pointa-i]+b[pointb-i];}
        for(i=1;flag==1&&pointa+i<500;i++) {a[pointa+i]=a[pointa+i]+b[pointb+i];}
        for(i=1;flag==0&&pointb+i<500;i++) {b[pointb+i]=a[pointa+i]+b[pointb+i];}

        for(i=499;i>0;i--)
        {
            if(i==pointa) continue;
            if(a[i]>=96) {a[i]=a[i]-48;}
            if(a[i]>=58&&i!=pointa+1)  { a[i]=a[i]-10; a[i-1]++;}
            if(a[i]>=58&&i==pointa+1)    {a[i]=a[i]-10; a[i-2]++;}
        }

        for(i=499;i>0;i--)
        {
            if(i==pointb) continue;
            if(b[i]>=96) {b[i]=b[i]-48;}
            if(b[i]>=58&&i!=pointb+1)  { b[i]=b[i]-10; b[i-1]++;}
            if(b[i]>=58&&i==pointb+1)    {b[i]=b[i]-10; b[i-2]++;}
        }

        if((a[0]/106)==1||(b[0]/106)==1||((a[0])>57&&a[0]<70)||(b[0]>57&&b[0]<70)) tem=1;
        if(a[0]>=96)  {a[0]=a[0]-48;}
        if(a[0]>=58)  { a[0]=a[0]-10;}
        if(b[0]>=96)  {b[0]=b[0]-48;}
        if(b[0]>=58)  { b[0]=b[0]-10;}

        if(tem!=0) printf("%d",tem);

        if(flag==1)
        {
            for(i=499;a[i]==0||a[i]=='0'||a[i]=='.';i--)
            {
                if(a[i]=='.') {a[i]=0;break;}
                a[i]=0;
            }
            for(i=0;a[i]!=0;i++)
                printf("%c",a[i]);
        }


        if(flag==0)
        {
            for(i=499;b[i]==0||b[i]=='0'||b[i]=='.';i--)
            {
                if(b[i]=='.') {b[i]=0;break;}
                b[i]=0;
            }
            for(i=0;b[i]!=0;i++)
                printf("%c",b[i]);
        }
        printf("\n");

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}
