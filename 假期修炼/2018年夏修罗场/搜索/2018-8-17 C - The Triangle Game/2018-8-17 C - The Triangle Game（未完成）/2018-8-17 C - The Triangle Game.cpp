// 2018-8-17 C - The Triangle Game.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[7][4];
int vis[7];
int dfs(int s,int v,int n,int tem) {
	if (n == 6) {
		if (tem == s) return v;
		else return 0;
	}
	for (int i = 0; i < 6; i++) {
		if (vis[i] == 1) continue;
		vis[i] = 1;
		if (a[i][0] == s) {
			int v1 = dfs(a[i][1], v + a[i][2], n + 1,tem);
			int v2 = dfs(a[i][2], v + a[i][1], n + 1,tem);
			return max(v1, v2);
		}
		if (a[i][1] == s) {
			int v1 = dfs(a[i][0], v + a[i][2], n + 1,tem);
			int v2 = dfs(a[i][2], v + a[i][0], n + 1,tem);
			return max(v1, v2);
		}
		if (a[i][2] == s) {
			int v1 = dfs(a[i][0], v + a[i][1], n + 1,tem);
			int v2 = dfs(a[i][1], v + a[i][0], n + 1,tem);
			return max(v1, v2);
		}
		vis[i] = 0;
		return 0;
	}
	return 0;
}
int main()
{
	while (1) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		}
		//printf("hahah\n");
		int ans = -1;
		vis[0] = 1;
		ans = max(dfs(a[0][1], a[0][0], 0, a[0][2]), ans);
		ans = max(dfs(a[0][2], a[0][1], 0, a[0][1]), ans);
		ans = max(dfs(a[0][1], a[0][2], 0, a[0][0]), ans);
		cout << ans << endl;
		string tem;
		cin >> tem;
		if (tem == "$") break;
	}
    return 0;
}

