// neuoj 1320 括号串.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5005;	
char tem[maxn];
int dp[maxn];
int init()
{
	for (int i = 0; i < maxn; i++)
	{
		dp[i] = 0;
		tem[i] = 0;
	}
	return 0;
}
int main()
{
	int T,len;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int k = 0;
		int ans=0;
		stack<int> a;
		init();
		scanf("%s", tem);
		len = strlen(tem);
		for(int j = 0; j < len; j++)
		{
			if (tem[j] == '(') a.push(++k);
			else if (tem[j]==')'&&!a.empty())
			{
				dp[a.top()] = dp[a.top() - 1] + 1;
				ans = dp[a.top()] + ans;
				a.pop();
			}
			else if(tem[j]==')')k++;
		}
		printf("Case #%d: %d\n", i, ans);
		        //Case #1: 2
	}
    return 0;
}

