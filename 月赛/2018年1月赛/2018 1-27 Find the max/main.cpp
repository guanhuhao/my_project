#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[100010];
int b[100010];
bool mycompare(int a,int b)
{
    return a>b;
}
int main()
{
    int T,i;
    int n,k,j;
    int tem,ans,p;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        ans=0;
        p=0;
        for(j=0;j<100010;j++) a[j]=-1,b[j]=0;
        scanf("%d%d",&n,&k);
        for(j=0;j<n;j++)
        {
            scanf("%d",&tem);
            if(a[tem]==-1)   {b[p]=1; a[tem]=p++;}
            else b[a[tem]]++;
        }
        sort(b,b+p,mycompare);
        //for(j=0;j<p;j++) printf("%d  ",b[j]);printf("\n");
        while(b[k-1]!=0)
        {
            //printf("%d\n",b[k-1]);
            ans=ans+b[k-1];
            for(j=0;j<k;j++) b[j]=b[j]-b[k-1];
            sort(b,b+p,mycompare);
        }
        printf("Case #%d:\n%d\n",i,ans);

    }
    return 0;
}
