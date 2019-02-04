// neuoj 1344 Eat walnuts again.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
ll dp[105][105];	
ll v[105];
ll DP(int i, int j)
{
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 1e9;
	for (int k = i; k <= j; k++)
		dp[i][j] = min(dp[i][j], DP(i, k - 1) + DP(k + 1, j) + (v[i-1] + v[k] + v[j+1])*(v[i - 1] + v[k] + v[j + 1]))%mod;
	return dp[i][j];
}
int main()
{
	int n;

	while (cin >> n)
	{
		memset(dp, -1, sizeof(dp));
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; i++) scanf("%lld", &v[i]);
		cout << DP(2, n - 1) << endl;
	}

    return 0;
}

