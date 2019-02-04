// Game Map2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m;
int ans;
struct Point {
	int flag;
	int head;
	int num;
	int tail;
}point[maxn];
struct Edge {
	int u, v;
}edge[maxn*6];
bool cmp( Edge a, Edge b) {
	return a.u < b.u;
}

void init() {
	for (int i = 0; i < n + 1; i++) {
		point[i].flag = point[i].head = point[i].tail = -1;
		point[i].num = 0;
	}
	for (int i = 0; i < m+5; i++) edge[i].u = edge[i].v = 0;
}
int dp(int a) {
	int _max = 1;
	for (int i = point[a].head; i <= point[a].tail; i++) {
		if (point[a].flag!=-1 && point[edge[i].u].num < point[edge[i].v].num) {
			point[edge[i].v].flag = 1;
			_max = max(_max, dp(edge[i].v) + 1);
			point[edge[i].v].flag = -1;
		}
	}
	return _max;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF) {
		int ans = 0;
		init();
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			scanf("%d%d", &tem1, &tem2);
			point[tem1].num++;
			point[tem2].num++;
			edge[2*i].u = tem1;
			edge[2*i].v = tem2;
			edge[2*i + 1].u = tem2;
			edge[2*i + 1].v = tem1;
		}
		sort(edge, edge + 2 * m,cmp);
		for (int i = 0; i < 2 * m; i++) {
			if (point[edge[i].u].head == -1 )point[edge[i].u].head = i;
			point[edge[i].u].tail = i;
		}
		for (int i = 0; i < n; i++) cout <<i<<"  "<< point[i].num << endl;
		int _min = maxn * 10;
		for (int i = 0; i < n; i++)_min = min(point[i].num, _min);
		for (int i = 0; i < n; i++) {
			if (point[i].num != _min) continue;
			point[i].flag = 1;
			for (int j = point[i].head; j < point[i].tail; j++) {
				point[edge[j].u].flag = 1;
				ans = max(ans, dp(edge[j].u) + 1);
				point[edge[j].u].flag = -1;
			}
			point[i].flag = -1;
		}
		printf("%d\n", ans);
	}
    return 0;
}

