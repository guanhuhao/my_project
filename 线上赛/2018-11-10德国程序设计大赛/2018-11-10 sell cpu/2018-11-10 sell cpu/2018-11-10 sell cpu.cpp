// 2018-11-10 sell cpu.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[105][105];	
int a[105][105];
int dfs(int no,int remain) {
	if (no == m||remain<=0) return 0;
	if (dp[no][remain]) return dp[no][remain];
	for (int i = 0; i <= n; i++) {
		if (i > remain) break;
		int tem = dp[no][remain];
		dp[no][remain] = max(dp[no][remain], dfs(no + 1, remain - i) + a[no][i-1]);
		//if (tem != dp[no][remain])cout << "text:" << no << " " << remain << " " << tem << " " << dp[no][remain] << endl;
	}
	return dp[no][remain];
}
int main()
{
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	dfs(0, n);
	cout << dp[0][n] << endl;
	//for (int i = 0; i < m; i++)
	//	for (int j = 0; j <= n; j++) cout << i + 1 << " " << j << " " << dp[i][j] << endl;
    return 0;
}

