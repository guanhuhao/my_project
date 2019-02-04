#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    int len;
    int a[100010];
    int i;
    int max;
    int ans;
    int tem;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        tem=0;
        scanf("%d",&len);
        max=-1;
        for(i=0;i<len;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>max) max=a[i];
        }
        //printf("%d",max);
        for(i=0;i<len;i++)
        {
            ans=ans+(max-a[i]);
            //printf("%d\n",ans);
        }
        printf("%d",ans);
        if(len==1)
        {
            printf("0 %d\n",a[0]);
            continue;
        }
        while(ans%(len-1)!=0)
        {
            ans=ans+len;
            tem++;
        }
        printf("%d %d\n",ans/(len-1),tem+max);
    }
    return 0;
}
