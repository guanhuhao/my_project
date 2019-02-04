// 2019-1-17 Fire!.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct P {
	int x, y;
};
int n, m;
char mapp[1010][1010];
int dis[2][1010][1010];
bool check(P a) {
	return a.x >= 0 && a.x < n&&a.y >= 0 && a.y<m&&mapp[a.x][a.y]!='#';
}
void bfs(int flag) {
	queue<P> que;
	if (flag == 1) {
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (mapp[i][j] == 'F') {
					que.push(P{ i,j });
					dis[1][i][j] = 0;
				}
			}
	}
	else {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if (mapp[i][j] == 'J') {
					que.push(P{ i,j });
					dis[0][i][j] = 0;
				}
	}
	while (!que.empty()) {
		//cout << "hahha" << endl;
		P p = que.front();
		que.pop();
		int dx[4] = { 0,0,-1,1 },
			dy[4] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i],
				yy = p.y + dy[i];
			if (check(P{ xx,yy })&&dis[flag][xx][yy]==-1) {
				dis[flag][xx][yy] = dis[flag][p.x][p.y] + 1;
				que.push(P{ xx,yy });
			}
		}
	}
}
int main()
{
	int T;
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(dis, -1, sizeof(dis));
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> mapp[i];
		bfs(0);
		bfs(1);
		int ans = 1e9+7;
		for (int k = 0; k <= 1; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
					cout << dis[k][i][j] << " ";
				cout << endl;
			}
			cout << endl << endl;
		}
		for (int i = 0; i < n; i++) {
			if (dis[0][i][0] != -1&&dis[0][i][0] < dis[1][i][0]) ans = min(ans, dis[0][i][0]);
			if (dis[0][i][m - 1] != -1&&dis[0][i][m - 1] < dis[1][i][m - 1]) ans = min(ans, dis[0][i][m - 1]);
		}
		for (int i = 0; i < m; i++) {
			if (dis[0][0][i] != -1&&dis[0][0][i] < dis[1][0][i]) ans = min(ans, dis[0][0][i]);
			if (dis[0][n-1][i] != -1&&dis[0][n-1][i] < dis[1][n-1][i]) ans = min(ans, dis[0][n-1][i]);			
		}
		if (ans == 1e9+7) cout << "IMPOSSIBLE" << endl;
		else cout << ans + 1<<endl;
	}
	return 0;
}

