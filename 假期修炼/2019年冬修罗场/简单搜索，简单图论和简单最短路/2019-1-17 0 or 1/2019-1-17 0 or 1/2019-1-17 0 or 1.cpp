// 2019-1-17 0 or 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int n;
int edge[305][305];
int vis[305];
int dis[305][305];
void init() {
	for (int i = 0; i < 305; i++)
		for (int j = 0; j < 305; j++) dis[i][j] = INF;
}
struct P {
	int num, v;
};
struct cmp {
	bool operator()(P a, P b) {
		return a.v > b.v;
	}
};
priority_queue<P, vector<P>, cmp> que;
void bfs(int start) {
	memset(vis, 0, sizeof(vis));
	dis[start][start] = 0;
	que.push(P{ start,0 });
	while (!que.empty()) {
		P top = que.top();
		que.pop();
		if (vis[top.num]) continue;
		
		vis[top.num] = 1;
		for (int i = 0; i < n; i++) {
			if (i == start) continue;
			if (dis[start][i] > dis[start][top.num] + edge[top.num][i]) {
				dis[start][i] = dis[start][top.num] + edge[top.num][i];
				que.push(P{ i,dis[start][top.num] + edge[top.num][i] });
			}
		}
		if (top.num == start) dis[start][start] = INF;
		dis[start][start] = min(dis[start][start], dis[start][top.num] + edge[top.num][start]);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	while (cin >> n) {
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> edge[i][j];
		}
		edge[0][0] = edge[n - 1][n - 1] = INF;
		bfs(0);
		bfs(n - 1);
		/*cout << "text:";
		for (int i = 0; i < n; i++)cout << dis[0][i] << " ";
		cout << endl;
		cout << "text:";
		for (int i = 0; i < n; i++)cout << dis[n-1][i] << " ";
		cout << endl;*/
		cout << min(dis[0][n - 1],dis[0][0]+dis[n-1][n-1]) << endl;
	}
    return 0;
}

