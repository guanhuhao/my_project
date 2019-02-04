// 2018-7-24 B - A计划.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char f[2][110][110];	
int ans[2][110][110];
int n, m, t;
int xe, ye,fe;
struct node {
	node(int xx, int yy, int ff) : x(xx), y(yy), f(ff) {}
	int x, y, f;
};
bool ok(int x, int y) {
	return x < n&&y < m&&x >= 0 && y >= 0;
}
queue<node> que;
void bfs() {
	int temx[4] = { 0,0,-1,1 };
	int temy[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		int x = que.front().x, y = que.front().y, fl = que.front().f;
		for (int i = 0; i < 4; i++) {
			int nx = x + temx[i], ny = y + temy[i];
			if (ok(nx, ny) && f[fl][nx][ny] != '*'&&ans[fl][nx][ny]==-1) {
				if (f[fl][nx][ny] == '#') {
					if (f[(fl + 1) % 2][nx][ny] == '#'||f[(fl + 1) % 2][nx][ny] == '*') continue;
					ans[fl][nx][ny] = ans[fl][x][y] + 1;
					if (ans[(fl + 1) % 2][nx][ny] == -1) {
						ans[(fl + 1) % 2][nx][ny] = ans[fl][x][y] + 1;
						que.push(node(nx, ny, (fl + 1) % 2));
					}
				}
				else {
					ans[fl][nx][ny] = ans[fl][x][y] + 1;
					que.push(node(nx, ny, fl));
				}
			}
		}
		que.pop();
	}
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		memset(ans, -1, sizeof(ans));
		cin >> n >> m >> t;
		for (int i = 0; i < n; i++) {
			cin >> f[0][i];
			for (int j = 0; j < m; j++) {
				if (f[0][i][j] == 'P') xe = i, ye = j, fe = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> f[1][i];
			for (int j = 0; j < m; j++) 
				if (f[1][i][j] == 'P') xe = i, ye = j,fe=1;
		}
		que.push(node(0, 0, 0));
		ans[0][0][0] = 0;
		bfs();
		cout << (ans[fe][xe][ye] <= t&&ans[fe][xe][ye]!=-1 ? "YES" : "NO") << endl;
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[0][i][j]<<"  ";
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << ans[1][i][j]<<"  ";
			cout << endl;
		}*/

	}
    return 0;
}

