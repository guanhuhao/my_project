// 2018-10-13 5.Games.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int a[1010];		
int n, d;
int ans = 0;
int rec[1005][11][1005];
bool vis[1005][11];
void init() {
	memset(rec, 0, sizeof(rec));
	memset(a, 0, sizeof(a));
	memset(vis, 0, sizeof(vis));
	ans=0;
}
void dfs(int n, int last) {
	if (n == 0) {
		rec[n][d][a[n]] = 1;
		return;
	}
	if (vis[n][last] == 1) return;	
	vis[n][last] = 1;
	if(last>=1)dfs(n - 1, last-1);
	dfs(n - 1, last);
	for (int i = 0; i <= 1000; i++) {
		if(last>=1)rec[n][last][i] += rec[n - 1][last - 1][i];
		rec[n][last][a[n] ^ rec[n - 1][last][i]] += rec[n - 1][last][i];
	}

}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		init();
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i <= d; i++) {
			dfs(n-1, i);
			ans += rec[n-1][i][0];
		}
		for (int i = 0; i < 5; i++) {
			if(rec[])
		}
		cout << ans << endl;
	}
    return 0;
}

