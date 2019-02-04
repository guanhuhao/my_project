#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T;
    int num;
    int i;
    int ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&num);
        i=1;
        while(i*i<=num)
        {
            if(num%i==0) ans++;
            i++;
        }
        printf("%d\n",ans%15498);
    }
    return 0;
}
