// 2018-7-26 F - Ordering Tasks.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[101][101];	
int vis[101];
int n, m;
void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[i][x] == 1) {
			dfs(i);
		}
	}
	if (!vis[x]) {
		printf("%d ", x);
		vis[x] = 1;
		for (int i = 1; i <= n; i++) {
			a[x][i] = 0;
		}
	}
}
int main()
{
	while (cin >> n >> m) {
		if (!n && !m) break;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			a[tem1][tem2] = 1;
		}
		int tem1, tem2;
		for (int i = 1; i <= n; i++) dfs(i);
		cout << endl;
	}
    return 0;
}

