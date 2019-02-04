// 2018-11-10 model railroad.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
vector<int> v1[maxn];
int vis[maxn];
void dfs1(int p) {
	if (vis[p] == 1) return;
	vis[p] = 1;
	for (int i = 0; i<v1[p].size(); i++) dfs1(v1[p][i]);

}
int fat[maxn];
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void uni(int x, int y) {
	int xx = findf(x);
	int yy = findf(y);
	if(xx!=yy) fat[xx] = fat[yy];
}
int main()
{
	for (int i = 0; i < maxn; i++) fat[i] = i;
	int flag = 0;
	memset(vis, 0, sizeof(vis));
	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v1[a].push_back(b);
		v1[b].push_back(a);
		if (i < l)uni(a, b);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (fat[i] == i) cnt++;
	dfs1(1);
	for (int i = 1; i <= n; i++) if (vis[i] == 0) flag = 1;
	if (m - l == cnt - 1) flag = 1;
	cout << (flag == 1 ? "impossible" : "possible" )<< endl;
    return 0;
}

