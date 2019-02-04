#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char du[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
    char a[110];
    int i,sum,tem[5];
    while(scanf("%s",a)!=EOF)
    {
        sum=0;
        for(i=0;i<5;i++) tem[i]=0;
        i=0;
        while(a[i]<58&&a[i]>47) sum=sum+a[i++]-48;
        for(i=0;sum!=0;i++)
        {
            tem[i]=sum%10;
            sum=sum/10;
        }
        for(i=4;tem[i]==0;i--);
        for(;i>-1;i--)
        {
            if(i!=0)printf("%s ",du[tem[i]]);
            else printf("%s\n",du[tem[i]]);
        }


    }
    return 0;
}
