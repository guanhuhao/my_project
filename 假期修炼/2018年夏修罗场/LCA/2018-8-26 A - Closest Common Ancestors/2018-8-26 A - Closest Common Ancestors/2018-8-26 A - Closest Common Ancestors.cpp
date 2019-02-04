// 2018-8-26 A - Closest Common Ancestors.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10100;
int vis[maxn];
int pre[maxn];
int fat[maxn];
int ans[maxn];
vector<int> v[maxn];
vector<int> q[maxn];

void init() {
		memset(vis, 0, sizeof(vis));
		memset(pre, -1, sizeof(pre));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < maxn; i++) {
			v[i].clear();
			q[i].clear();
		}
		for (int i = 0; i < maxn; i++) fat[i] = i;
}
int findf(int a) {
	if (a == fat[a]) return a;
	return fat[a] = findf(fat[a]);
}
void uni(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	fat[x] = fat[y];
}
void dfs(int sta) {	
	vis[sta] = 1;
	int nn = q[sta].size();
	for (int j = 0; j < nn; j++) {
		if (vis[q[sta][j]]) {
			ans[findf(q[sta][j])]++;
		}
	}
	int size = v[sta].size();
	for (int i = 0; i < size; i++) {
		dfs(v[sta][i]);	
	}
	uni(sta, pre[sta]);	
}
int main()
{
	int n;
	while (scanf("%d", &n)!=EOF) {
		//cout << "text:" << n << endl;
		init();
		for (int i = 0; i < n; i++) {
			int tem1, tem2;
			scanf("%d:(%d)", &tem1, &tem2);
			for (int j = 0; j < tem2; j++) {
				int tem;
				scanf ("%d",&tem);
				v[tem1].push_back(tem);
				pre[tem] = tem1;
			}
		}
		int m;
		scanf("%d%*c",&m);
		for (int i = 0; i < m; i++) {
			int tem1,tem2;
			while (getchar() != '(');
			scanf("%d %d)", &tem1, &tem2);		
			//cout <<"text:"<< tem1 <<" "<< tem2 << endl;
			q[tem1].push_back(tem2);
			q[tem2].push_back(tem1);
		}
		int sta;
		for (int i = 1; i <= n; i++) if (pre[i] == -1)sta = i;
		//cout << "text:" << "hahah" << endl;
		dfs(sta);
		for (int i = 0; i <= n; i++) {
			if (ans[i] != 0) printf("%d:%d\n", i, ans[i]);
		}
	}
    return 0;
}

