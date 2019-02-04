// Game Map.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m;
int flag[maxn];
vector<int> edge[maxn];
bool cmp(vector<int> a, vector<int> b) {
	return a.size() < b.size();
}
int ans;
int dp(int a) {
	int _max = 1;
	for (int i = 0; i < edge[a].size(); i++) {
		if (!flag[edge[a][i]] && edge[a].size() <= edge[edge[a][i]].size()) {
			flag[edge[a][i]] = 1;
			_max = max(_max, dp(edge[a][i])+1);
			flag[edge[a][i]] = 0;
		}
	}
	return _max;
}
void init() {
	for (int i = 0; i < n; i++) edge[i].clear();
	memset(flag, 0, sizeof(flag));
}
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF) {
		init();
		ans = 0;
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			scanf("%d%d", &tem1, &tem2);
			edge[tem1].push_back(tem2);
			edge[tem2].push_back(tem1);
		}
		sort(edge, edge + n,cmp);
		for (int i = 0; i < n; i++) cout << edge[i].size()<<endl;
		for (int i = 0; i < n&&edge[i].size() == edge[0].size(); i++) {
			flag[i] = 1;
			for (int j = 0; j < edge[i].size(); j++) {
				flag[j] = 1;
				ans = max(ans, dp(edge[i][j])+1);
				flag[j] = 0;
			}
			flag[i] = 0;
		}
		printf("%d\n", ans);
	}
    return 0;
}

