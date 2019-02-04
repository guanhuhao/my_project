#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int T,i,a;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&a);
        printf("Case #%d: %d\n",i,a/2);
    }
    return 0;
}
