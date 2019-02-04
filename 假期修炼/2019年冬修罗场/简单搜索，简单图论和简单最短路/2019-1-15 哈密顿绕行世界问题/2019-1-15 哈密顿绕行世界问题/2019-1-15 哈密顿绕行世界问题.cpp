// 2019-1-15 哈密顿绕行世界问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
	return a < b;
}
int edge[25][3];
int vis[25];
int cnt;
void dfs(int s,vector<int> v) {
	for (int i = 0; i < 3; i++) {
		if (vis[edge[s][i]]) continue;
		vis[edge[s][i]] = 1;
		v.push_back(edge[s][i]);
		dfs(edge[s][i], v);
		v.pop_back();
		vis[edge[s][i]] = 0;
	}
	if (v.size() == 20&&(v[19]==edge[v[0]][0]|| v[19] == edge[v[0]][1]|| v[19] == edge[v[0]][2])) {

		cout << ++cnt << ":  ";
		for (int i = 0; i < 20; i++) cout << v[i] << " ";
		cout << v[0] << endl;
	}
}
int main()
{
	while (cin >> edge[1][0]&&edge[1][0]) {
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		int s;
		cin >> edge[1][1] >> edge[1][2];
		for (int i = 2; i <= 20; i++) cin >> edge[i][0] >> edge[i][1] >> edge[i][2];	
		cin >> s;
		for (int i = 1; i <= 20; i++) sort(edge[i], edge[i] + 3, cmp);
		vis[s] = 1;
		vector<int> v{s};
		dfs(s,v);
	}
    return 0;
}

