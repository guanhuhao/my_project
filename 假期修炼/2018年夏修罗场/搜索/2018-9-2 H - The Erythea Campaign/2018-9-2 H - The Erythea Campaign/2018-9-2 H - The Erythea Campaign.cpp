// 2018-9-2 H - The Erythea Campaign.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <bits/stdc++.h>
using namespace std;
int t,m,n;
int mapp[100][100];
int risk[100][100];
int vis[100][100];
int ans[100][100];
int sx, sy, ex, ey;
void init() {
	memset(ans, 0, sizeof(ans));
	memset(risk, -1, sizeof(risk));
}
bool check(int x, int y) {
	return x<0 || x>m || y<0 || y>n;
}
bool check2(int x, int y) {
	return x < 0 || x >= m || y < 0 || y >= n;
}
struct P {
	int x, y;
	int value;
	P(int xx, int yy, int vv) { x = xx; y = yy; value = vv; }
};
void bfs() {	
	memset(vis, 0, sizeof(vis));
	queue<P> que;
	int comx[4] = { 0,0,-1,-1 };
	int comy[4] = { 0,-1,0,-1 };
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + comx[k];
				int y = j + comy[k];
				if (check2(x,y))continue; //bug
				if(mapp[x][y])cnt++;
			}
			if (cnt>0) {
				vis[i][j] = 1;
				if (cnt < 4) {
					que.push(P{ i,j,0 });
					risk[i][j] = m + n;
				}
			}
		}
	}
	int comx2[4] = { 0,0,-1,1 };
	int comy2[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		P tem = que.front();
		que.pop();
		int xx = tem.x, yy = tem.y;
		for (int i = 0; i < 4; i++) {
			int temx = xx + comx2[i];
			int temy = yy + comy2[i];
			if (check(temx, temy)||vis[temx][temy])continue;
			vis[temx][temy] = 1;
			risk[temx][temy] = risk[xx][yy] - 1;
			que.push(P{ temx,temy,0 });
		}
	}
}
bool bound(int x, int y) {
	return x == 0 || x == m || y == 0 || y == n;
}
struct cmp {
	bool operator()(P a, P b) {
		return a.value>b.value;
	}
};
void bfs2(int x, int y) {
	memset(vis, 0, sizeof(vis));
	priority_queue<P,vector<P>,cmp> que;
	que.push(P{ x,y,risk[x][y] });
	ans[x][y] = risk[x][y];
	while (!que.empty()) {
		P tem = que.top();
		que.pop();
		int xx = tem.x;  int yy = tem.y;
		if (vis[xx][yy] == 1) continue;
		ans[xx][yy] = tem.value;
		vis[xx][yy] = 1;
		int temx = xx - 1; int temy = yy;
		if (!check(temx, temy) && !vis[temx][temy] && (yy==0||yy==n||!mapp[xx - 1][yy - 1] || !mapp[xx - 1][yy])) 
			que.push(P{ temx,temy,tem.value + risk[temx][temy] });

		temx = xx, temy = yy + 1;
		if (!check(temx, temy) && !vis[temx][temy] && (xx==0||xx==m||(mapp[xx - 1][yy] + mapp[xx][yy])!=2))
			que.push(P{ temx,temy,tem.value + risk[temx][temy] });

		temx = xx + 1, temy = yy;
		if(!check(temx,temy)&&!vis[temx][temy]&&(yy==0||yy==n||!mapp[xx][yy-1]||!mapp[xx][yy]))
			que.push(P{ temx,temy,tem.value + risk[temx][temy] });

		temx = xx, temy = yy - 1;
		if (!check(temx, temy) && !vis[temx][temy] && (xx==0||xx==m||!mapp[xx - 1][yy - 1] || !mapp[xx][yy - 1]))
			que.push(P{ temx,temy,tem.value + risk[temx][temy] });
	}

}
int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		scanf("%d%d", &m, &n);
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				scanf("%1d", &mapp[i][j]);
		}
		bfs();

		bfs2(sx,sy);
		/*for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++)
				printf("%3d  ", risk[i][j]);
			cout << endl;
		}
		cout << endl << endl;
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++)
				printf("%3d  ", ans[i][j]);
			cout << endl;
		}*/
		if(ans[ex][ey])cout << ans[ex][ey] << endl;
		else cout << "no solution" << endl;
	}
}