// 2018-7-24 G - Battle City.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char a[303][303];
int ans[303][303];	
struct node {
	int x, y, v;
	node(int xx = 0, int yy = 0, int vv = 0) :x(xx), y(yy), v(vv) {};
};
struct cmp {
	bool operator ()(node a, node b) {
		return a.v > b.v;
	}
};
priority_queue<node, vector<node>, cmp > que;
int n, m;
int xs, ys, xe, ye;
bool ok(int x, int y) {
	return x < n&&x >= 0 && y < n&&y >= 0;
}
void bfs() {
	int temx[4] = { 0,0,1,-1 };
	int temy[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		int x = que.top().x, y = que.top().y;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + temx[i], ny = y + temy[i];
			if (ok(nx, ny) && ans[nx][ny] == -1 && a[nx][ny] != 'R'&&a[nx][ny] != 'S') {
				if (a[nx][ny] == 'E') {
					que.push(node(nx, ny, 1));
					ans[nx][ny] = ans[x][y] + 1;
				}
				else {
					que.push(node(nx, ny, 2));
					ans[nx][ny] = ans[x][y] + 2;
				}
			}
		}
	}
}
int main()
{

	while (cin >> n >> m) {
		if (!n && !m) break;
		memset(ans, -1, sizeof(ans));
		for (int i = 0; i < n; i++) {
			cin >> m;
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'Y') {
					xs = i, ys = j;
					que.push(node(i, j,1));
					ans[i][j] = 0;
				}
				if (a[i][j] == 'T')xe = i, ye = j;
			}
		}
		bfs();
		cout << ans[xe][ye] << endl;
	}
    return 0;
}

