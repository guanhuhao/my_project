#include <stdio.h>
#include <stdlib.h>
char a[220][22];
char blue[220][22];
int main()
{
    int T,i,j,n,count1,count2;
    double pre[220],sum;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)  scanf("%s",a[i]);
        for(i=0;i<n;i++)  scanf("%s",blue[i]);

        for(i=0;i<n;i++)
        {
            count1=count2=0;
            j=0;
            while(a[i][j]!='\0')
            {
                count2++;
                if(a[i][j]==blue[i][j]) count1++;
                j++;
            }
            pre[i]=(float)count1/count2;
        }
        for(i=0;i<n;i++)  sum=sum+pre[i];

        printf("%.2lf%%\n",(sum/n)*100);

    }
    return 0;

}
