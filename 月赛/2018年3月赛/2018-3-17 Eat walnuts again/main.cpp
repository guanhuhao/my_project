#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 100000000
using namespace std;
vector<int> a;
vector<int> b;

int main()
{
    int i,num;
    int mini,point;
    int tem;
    long long ans;
    while(scanf("%d",&num)!=EOF)
    {
        ans=0;
        for(i=0; i<num; i++)
        {
            scanf("%d",&tem);
            a.push_back(tem);
           // printf("%d\n",i);
        }

        b.push_back(MAX);
        for(i=1; i<a.size()-1; i++)
        {
            b.push_back(a[i-1]+a[i+1]);
           // printf("%d\n",i);
        }
        b.push_back(MAX);
        while(a.size()>2)
        {
            mini=MAX;

            for(i=0; i<b.size(); i++)
            {
                if(b[i]>=mini)   continue;
                mini=b[i];
                point=i;
            }
            ans=ans+(long long)(mini+a[point])*(mini+a[point]);
            printf("%d  %d\n",mini,mini+a[point]);
           // printf("%d\n",i) ;
            a.erase(a.begin()+point);
            b.erase(b.begin()+point);
            if(point-2>=0)  b[point-1]=a[point-2]+a[point];
            if(point+1<a.size()-1)  b[i]=a[point-1]+a[point+1];
            printf("\n%d     %d\n",b[point-1],b[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
