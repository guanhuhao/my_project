// 2018-10-2 Tourists.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> v[maxn];
int vis[maxn];
int ans = 0;	
int n;
int cnt;
void dfs(int a,int tar,int deep) {
	if (cnt >= n / tar) return;
	if (a%tar == 0&&a!=tar) {
		ans += deep;
		cnt++;
	}
	for (int i = 0; i < v[a].size(); i++) {
		if (vis[v[a][i]] == 1) continue;
		vis[v[a][i]] = 1;
		dfs(v[a][i],tar,deep+1);
	}
}
int main()
{	

	while (scanf("%d",&n)!=EOF) {
		ans = 0;
		for (int i = 0; i < maxn; i++)v[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n / 2; i++) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			cnt = 0;
			dfs(i, i, 1);
		}
		printf("%d\n", ans);
	}
    return 0;
}

