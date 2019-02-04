// 2019-1-14 简单搜索 Oil Deposits.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>
#include <cstring>
using namespace std;
char mapp[105][105];
int cnt;
int dx[8] = { -1,-1,-1,0,0,1,1,1};
int dy[8] = { -1,0,1,-1,1,-1,0,1};
int n, m;
bool check(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < m&&mapp[x][y] == '@';
}
void dfs(int x, int y) {
	mapp[x][y] = '*';
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i],
			yy = y + dy[i];
		if(check(xx,yy)) dfs(xx, yy);
	}
}
int main()
{
	while (cin >> n >> m&&n) {
		cnt = 0;
		for (int i = 0; i < n; i++) cin >> mapp[i];
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (mapp[i][j] == '@') {
					dfs(i, j);
					cnt++;
				}
			}
		cout << cnt << endl;
	}
    return 0;
}

