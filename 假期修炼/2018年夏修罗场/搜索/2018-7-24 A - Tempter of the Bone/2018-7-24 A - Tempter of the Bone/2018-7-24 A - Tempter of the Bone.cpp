// 2018-7-24 A - Tempter of the Bone.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char a[8][8];
int b[8][8];	
int n, m, t;
int w;
queue<pair<int, int> > que;
bool ok(int x, int y) {
	if (x < n&&x >= 0 && y < m&&y >= 0 &&( a[x][y] == '.'||a[x][y]=='S')) return true;
	else return false;
}
int bfs() {
	int tema[4] = { 0,0,-1,1 };
	int temb[4] = { 1,-1,0,0 };
	while (!que.empty()) {
		int x = que.front().first, y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (ok(x + tema[i], y + temb[i]) && b[x + tema[i]][y + temb[i]] == -1) {
				que.push(pair<int, int>(x + tema[i], y + temb[i]));
				b[x + tema[i]][y + temb[i]] = b[x][y] + 1;
			}
		}
	}
	return 0;
}
int dfs(int x,int y,int bu) {
	if (a[x][y] == 'D'&&bu == t) return 1;
	if (bu + b[x][y] > t) return 0;
	int tema[4] = { 0,0,-1,1 };
	int temb[4] = { 1,-1,0,0 };
	a[x][y] = '#';
	for (int i = 0; i < 4; i++) {
		if (ok(x + tema[i], y + temb[i])) {
			if (dfs(x + tema[i], y + temb[i], bu + 1)) return 1;
		}
	}
	a[x][y] = '.';
	return 0;
}
int main()
{

	while (cin >> n >> m >> t) {
		w = 0;
		int x, y;
		memset(b, -1, sizeof(b));
		while (!que.empty()) que.pop();
		if (n == m&&m == t&&t == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'X') w++;
			}
		}
		int text = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'S' || a[i][j] == 'D'){
					text =text+ i + j;
					if (a[i][j] == 'D') que.push(pair<int, int>(i, j)),b[i][j]=0;
					else x = i, y = j;
				}
			}
		}

		if (text % 2 != t % 2) cout << "NO" << endl;
		else {
			bfs();
			if (b[x][y] > t) cout << "NO" << endl;
			else if (b[x][y] == t) cout << "YES" << endl;
			else {
				if (dfs(x, y, 0))cout << "YES";
				else cout << "NO" << endl;
			}
		}	
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << b[i][j] ;
			cout << endl;
		}*/

	}
    return 0;
}

