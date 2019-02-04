// 2018-7-25 G - Battle City.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n, m;
int xe, ye;
char a[303][303];
int ans[303][303];
struct cmp {
	bool operator()(pair<int, int> tema, pair<int, int> temb) {
		return ans[tema.first][tema.second]>ans[temb.first][temb.second];
	}
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> que;
bool ok(int x, int y) {
	return x >= 0 && y >= 0 && x < n&&y < m;
}
void bfs() {
	int temx[4] = { 0,0,-1,1 };
	int temy[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		int x = que.top().first, y = que.top().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temx[i] + x, ny = temy[i] + y;
			if (ok(nx, ny) && a[nx][ny] != 'R'&&a[nx][ny] != 'S'&&ans[nx][ny] == -1) {
				if (a[nx][ny] == 'B') {
					ans[nx][ny] = ans[x][y] + 2;
					que.push(pair<int, int>(nx, ny));
				}
				else {
					ans[nx][ny] = ans[x][y] + 1;
					que.push(pair<int, int>(nx, ny));
				}
			}
		}
	}
}

int main()
{
	while (cin >> n >> m) {
		memset(ans, -1, sizeof(ans));
		if (!n && !m) break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'Y') {
						que.push(pair<int, int>(i, j));
						ans[i][j] = 0;
				}
				else if (a[i][j] == 'T') {
					xe = i, ye = j;
				}
			}
		}
		bfs();
		cout << ans[xe][ye] << endl;
	}
    return 0;
}

