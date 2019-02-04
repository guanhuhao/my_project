// 2018-8-19 Drainage Ditches.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
const int INF = (int) 1e9 + 7;
int ma[250][250];
int vis[250];
int dfs(int s, int t, int f) {
	if (s == t) return f;
	vis[s] = 1;
	for (int i = 0; i < 250; i++) {
		if (!vis[i] && ma[s][i] > 0) {	
			//cout << "text:" << s << " " << i <<" "<<f<< " "<<ma[s][i] <<endl;
			int d = dfs(i, t, min(f, ma[s][i]));
		
			if (d > 0) {
				ma[s][i] -= d;
				ma[i][s] += d;
				return d;
			}
		}
	}
	return 0;
}
int main()
{
	int n, m;

	while (cin >> n >> m) {
		memset(ma, 0, sizeof(ma));
		for (int i = 0; i < n; i++) {
			int tem1, tem2, tem3;
			cin >> tem1 >> tem2 >> tem3;
			ma[tem1][tem2] += tem3;
			//cout << "text:" << tem1 << " " << tem2 << " " << ma[tem1][tem2] << endl;
		}
		int ans = 0;
		while (1) {
			memset(vis, 0, sizeof(vis));
			int f = dfs(1, m, INF);
			if (f == 0) break;
			ans += f;
		}
		cout << ans << endl;
	}
    return 0;
}

