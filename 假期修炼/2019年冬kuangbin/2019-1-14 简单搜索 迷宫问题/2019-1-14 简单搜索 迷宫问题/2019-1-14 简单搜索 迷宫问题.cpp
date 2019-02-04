// 2019-1-14 简单搜索 迷宫问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
queue<P> que;
int mapp[10][10];
int ans[10][10];
bool check(int x, int y) {
	return x < 5 && y < 5 && x >= 0 && y >= 0;
}
void bfs() {
	ans[0][0] = 0;
	que.push(P{ 0, 0 });
	while (!que.empty()) {
		P top = que.front();
		que.pop();
		int dx[4] = { 0,0,1,-1 },
			dy[4] = { 1,-1,0,0 };
		for (int i = 0; i < 4; i++) {
			int xx = dx[i] + top.first,
				yy = dy[i] + top.second;
			if (check(xx, yy) && ans[xx][yy] == -1&&mapp[xx][yy]!=1) {
				ans[xx][yy] = ans[top.first][top.second] + 1;
				que.push(P{ xx,yy });
			}
		}
	}
}
void dfs(int x,int y) {
	if (!x && !y) {
		cout << "(0, 0)" << endl;
		return;
	}
	int dx[4] = { 0,0,1,-1 },
		dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int xx = dx[i] + x,
			yy = dy[i] + y;
		if (check(xx, yy) && ans[xx][yy] == ans[x][y] - 1) {
			dfs(xx, yy);
			cout << "(" << x << ", " << y << ")" << endl;

			break;
		}
	}
}
int main()
{
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			cin >> mapp[i][j];

	bfs();
	dfs(4,4);	
    return 0;
}

