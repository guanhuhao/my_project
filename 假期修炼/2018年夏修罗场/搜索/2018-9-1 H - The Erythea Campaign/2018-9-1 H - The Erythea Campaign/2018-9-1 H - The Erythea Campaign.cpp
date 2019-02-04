// 2018-9-1 H - The Erythea Campaign.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int t,m,n;
int x1, x2,yy, y2;
int mapp[100][100];
int risk[100][100];
int vis[100][100];
int ans[100][100];
int comx[4] = { 0,0,1,-1 };
int comy[4] = { 1,-1,0,0 };
int comx2[4] = { -1,-1,0,0 };
int comy2[4] = { 0,-1,-1,0 };
struct P {
	int x, y;
	P(const P & a) { x = a.x; y = a.y; }
	P(int xx, int yy) { x = xx; y = yy; }
};
void init() {
	memset(risk, -1, sizeof(risk));
	memset(mapp, 0, sizeof(m));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			ans[i][j] = 10000000;
}
int check(int x,int y){
	return x > m || x<0 || y>n || y < 0;
}
void bfs() {
	queue<P> que;
	for(int i=0;i<=m;i++){
		for (int j = 0; j <= n; j++) {
			int tem = 0;
			for (int k = 0; k < 4; k++) {
				int temx = i + comx2[k];
				int temy = j + comy2[k];
				if (check(temx,temy)) continue;
				if (mapp[temx][temy] == 1) tem++;
			}
			if (tem == 0) continue;
			vis[i][j] = 1;
			if (tem != 4) {
				que.push(P{ i,j });
				//cout << "text:" << i << " " << j << endl;
				risk[i][j] = n+m;
			}
		}
	}
//	cout << "hahah" << endl;
	while (!que.empty()) {
		P tem = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int temx = tem.x + comx[i];
			int temy = tem.y + comy[i];
			if (check(temx, temy)||vis[temx][temy]==1) continue;
			risk[temx][temy] = risk[tem.x][tem.y] - 1;
			que.push(P{ temx,temy });
			vis[temx][temy] = 1;
		}
	}
}
struct cmp{
	bool operator()(P a, P b) {
		return ans[a.x][a.y] > ans[b.x][b.y];
	}
};
void bfs2(int x,int y) {
	ans[x][y] = risk[x][y];
	priority_queue<P,vector<P>,cmp> que;
	que.push(P{x,y});
	while (!que.empty()) {
		P tem = que.top();	cout << "1" << endl;
		que.pop();
		cout << "2" << endl;
		int xx = tem.x;
		int yy = tem.y;
		if (vis[xx][yy]) continue;
		vis[xx][yy] = 1;
		
		for (int i = 0; i < 4; i++) {
			int temx = tem.x + comx[i];
			int temy = tem.y + comy[i];
			if (check(temx, temy) || risk[temx][temy] == -1||vis[temx][temy]) continue;
			if (i == 0 && mapp[xx - 1][yy] && mapp[xx][yy]) continue;
			if (i == 1 && mapp[xx - 1][yy - 1] && mapp[xx][yy - 1]) continue;
			if (i == 2 && mapp[xx][yy - 1] && mapp[xx][yy]) continue;
			if (i == 3 && mapp[xx - 1][yy - 1] && mapp[xx - 1][yy]) continue;
			ans[temx][temy] = ans[tem.x][tem.y] + risk[temx][temy];
			que.push(P{temx,temy});
		
		}
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		init();
		scanf("%d%d", &m, &n);
		scanf("%d%d%d%d", &x1, &yy, &x2, &y2);
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < n; j++) 
				scanf("%1d", &mapp[i][j]);

		bfs();	
		memset(vis, 0, sizeof(vis));
		bfs2(x1,yy);
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
		printf("%d\n", ans[x2][yy]);
	}
    return 0;
}


