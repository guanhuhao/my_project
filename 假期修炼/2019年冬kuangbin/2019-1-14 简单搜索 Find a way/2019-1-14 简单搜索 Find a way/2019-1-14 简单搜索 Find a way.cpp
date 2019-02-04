// 2019-1-14 简单搜索 Find a way.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct P {
	int x, y;
};
char mapp[205][205];
int ans[2][205][205];
queue<P> que[2];
vector<P> v;
P p[2];
int n, m;
bool check(int a, P b) {
	return b.x >= 0 && b.x < n&&b.y >= 0 && b.y < m&&mapp[b.x][b.y] != '#'&&mapp[b.x][b.y] != 'M'&&mapp[b.x][b.y] != 'Y'&&ans[a][b.x][b.y] == -1;
}
void bfs(int a) {
	que[a].push(p[a]);
	ans[a][p[a].x][p[a].y] = 0;
	while (!que[a].empty()) {
		P top = que[a].front();
		que[a].pop();
		int dx[4] = { 0,0,1,-1 },
			dy[4] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int xx = top.x + dx[i],
				yy = top.y + dy[i];
			if (check(a, P{ xx,yy })) {
				que[a].push(P{ xx,yy });
				ans[a][xx][yy] = ans[a][top.x][top.y] + 1;
			}
		}
	}

}
int main()
{
	while (cin>>n>>m) {
		v.clear();
		memset(ans, -1, sizeof(ans));
		for (int i = 0; i < n; i++) cin >> mapp[i];
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (mapp[i][j] == 'Y') {
					p[0].x = i;
					p[0].y = j;
				}
				else if (mapp[i][j] == 'M') {
					p[1].x = i;
					p[1].y = j;
				}
				else if (mapp[i][j] == '@') {
					v.push_back(P{ i,j });
				}
			}
		bfs(0);
		bfs(1);
		/*cout << "text:" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) cout << ans[1][i][j] << " ";
			cout << endl;
		}
		cout << endl;*/
		int out=10000000;
		for (int i = 0; i < v.size(); i++) {
			if (ans[0][v[i].x][v[i].y] == -1 || ans[1][v[i].x][v[i].y] == -1) continue;
			out = min(out, ans[0][v[i].x][v[i].y] + ans[1][v[i].x][v[i].y]);
		}
		cout << out * 11 << endl;
	}
    return 0;
}

