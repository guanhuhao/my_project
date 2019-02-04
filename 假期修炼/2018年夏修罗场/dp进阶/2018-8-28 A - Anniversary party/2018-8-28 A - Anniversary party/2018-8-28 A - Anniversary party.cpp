// 2018-8-28 A - Anniversary party.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 6060;
vector<int> v[maxn];
int pre[maxn];
int hap[maxn];
int dp[maxn][2];
void init() {
	memset(pre, -1, sizeof(pre));
	memset(hap, 0, sizeof(hap));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < maxn; i++) v[i].clear();
}
void dfs(int sta) {
	int size = v[sta].size();
	if (size == 0) {
		dp[sta][0] = 0;
		dp[sta][1] = max(hap[sta], 0);
		return;
	}
	for (int i = 0; i < size; i++) {
		int next = v[sta][i];
		dfs(next);
		dp[sta][0] += max(dp[next][1], dp[next][0]);
		dp[sta][1] += dp[next][0];
	}
	dp[sta][1] += hap[sta];
	int tem1 = 0, tem2 = 0;
}
int main()
{
	ios::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		init();
		for (int i = 1; i <= n; i++) cin >> hap[i];
		int low, high;
		while (cin >> low >> high&&low&&high) {
			pre[low] = high;
			v[high].push_back(low);
		}
		int sta = 0;
		for (int i = 1; i <= n; i++) if (pre[i] == -1) sta = i;
		dfs(sta);
		//for (int i = 1; i <= n; i++)cout << "text:" << dp[i][0] << " " << dp[i][1] << endl;
		cout << max(dp[sta][0], dp[sta][1]) << endl;
	}
	return 0;
}
