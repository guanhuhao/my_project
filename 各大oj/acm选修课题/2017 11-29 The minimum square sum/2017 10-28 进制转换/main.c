#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,R,i,num,flag;
    char a[100];
    while(scanf("%d%d",&N,&R)!=EOF)
    {
        flag=0;
        for(i=0;; i++)
        {
            if(N<0)
            {
                flag=1;
                N=-N;
            }
            a[i]=N%R;
            N=(N-a[i])/R;
            if(N==0)  break;
        }


        num=i;
        for(i=0; i<num+1; i++)
        {
            if(a[i]<10&&a[i]>-1) a[i]=a[i]+48;
            else if(a[i]>=10) a[i]=a[i]+55;
        }
        if(flag==1) printf("-");
        for(i=num; i>-1; i--)
        {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}
