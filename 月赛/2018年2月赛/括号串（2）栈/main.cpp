#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int len,ans;
char tem[5005];
int dp[5005];

int init()
{
    int i;
    for(i=0;i<5005;i++){
        tem[i]=0;
        dp[i]=0;
    }
    return 0;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        ans=0;
        k=0;
        init();
        stack<int> a;
        scanf("%s",tem);
        len=strlen(tem);
        for(j=0;j<len;j++){
            if(tem[j]=='(') a.push(++k);
            else if(!a.empty()){
                k=a.top();
                dp[a.top()]=dp[a.top()-1]+1;
                ans=ans+dp[a.top()];
                a.pop();
            }
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
