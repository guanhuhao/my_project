#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;



int main()
{
    int T,i,t,flag,n,m;
    int a[1010],b[1010];
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            t=0;
            flag=0;
            scanf("%d%d",&n,&m);
            for(i=0; i<n; i++) scanf("%d",&a[i]);
            for(i=0; i<m; i++) scanf("%d",&b[i]);
            sort(a,a+n);
            if(n<m) printf("Never WOW.\n");
            else
            {
                for(i=0;i<n;i++)
                {
                    t=t+a[i];
                    if(t>b[i])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) printf("Never WOW.\n");
                else printf("Wow!\n");
            }

        }
    }
    return 0;
}
