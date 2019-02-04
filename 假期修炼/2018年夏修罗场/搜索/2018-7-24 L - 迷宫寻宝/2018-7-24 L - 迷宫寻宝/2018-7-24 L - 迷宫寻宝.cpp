// 2018-7-24 L - 迷宫寻宝.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int ans[1010][1010];	
int n;
int xe, ye;
queue<pair<int, int> > que;
bool ok(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < n;
}
void bfs() {
	int temx[4] = { 0,0,1,-1 };
	int temy[4] = { 1,-1,0,0 };
	/*while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		a[x][y] = '#';
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (ok(x + temx[i], y + temy[i]) && a[x + temx[i]][y + temy[i]] != '#'&&ans[x + temx[i]][y + temy[i]]==-1) {
				que.push(pair<int, int>(x + temx[i], y + temy[i]));
				a[x + temx[i]][y + temy[i]] = '#';
				ans[x + temx[i]][y + temy[i]]= ans[x][y] + 1;
			}
			if (x + temx[i] == xe&&y + temy[i] == ye) return;
		}
	}*/
	while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + temx[i], ny = temy[i] + y;
			if (ok(nx, ny) && a[nx][ny] != '#'&&ans[nx][ny] == -1) {
				que.push(pair<int, int>(nx, ny));
				ans[nx][ny] = ans[x][y] + 1;
			}
		}
	}
}
int main()
{
	cin >> n;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'S') {
				que.push(pair<int, int>(i, j));
				ans[i][j] = 0;
			}
			if (a[i][j] == 'E') xe = i, ye = j;
		}
	}
	bfs();
	//cout << xe << ye;
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ans[i][j]<<" ";
		cout << endl;
	}*/
	cout << ans[xe][ye]<<endl;
    return 0;
}

