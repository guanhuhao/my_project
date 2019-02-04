// 2018-8-29 B - The Accomodation of.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
vector<int> v[maxn];

int vis[maxn];
int flag = 0;
void init() {
	for (int i = 0; i < maxn; i++) v[i].clear();
	flag = 0;
	memset(vis, -1, sizeof(vis));
}
void dfs(int a, int value) {
	if (flag == 1)return;
	if (vis[a] != -1) {
		for (int i = 0; i < v[a].size(); i++){
			if (vis[a] == vis[v[a][i]]) {
				flag = 1;
				return;
			}
		}
		return;
	}
	vis[a] = value;
	for (int i = 0; i < v[a].size(); i++) {
		cout << "text:" << a << " " << v[a][i] << " " << vis[a] << " " << !value << endl;
		dfs(v[a][i], !value);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			v[tem1].push_back(tem2);
			v[tem2].push_back(tem1);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] != -1) continue;
			dfs(i,0);
		}
		if (flag == 1) {
			cout << "No" << endl;
			continue;
		}

	
	}
    return 0;
}

