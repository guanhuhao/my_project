// neuoj 1345 Advice from the elderly.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "cstdio"
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

int main()
{
	int T;
	int num, money;
	int value[1005];
	int time[1005];
	int pay[1005];
	int dp[1005];
	int ans;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 1005; i++) dp[i] = 0;
		scanf("%d%d", &num, &money);
		for (int i = 0; i < num; i++)	scanf("%d%d%d", &value[i], &pay[i], &time[i]);
		for (int i = 0; i < num; i++)
			for (int j = money;j>=0; j--)	
				for (int k = 1; k <= time[i]&&j+k*pay[i]<=money; k++)
				{
					if (dp[j+ k*pay[i]] < dp[j] + value[i] * k) dp[k*pay[i]] = dp[j] + value[i] * k;
					//printf("%d  %d\n", j + k*pay[i], dp[j + k*pay[i]]);
				}
		ans = 0;
		for (int i = 0; i <= money; i++)	ans = max(ans, dp[i]);
		printf("%d\n", ans);

	}
	return 0;
}

