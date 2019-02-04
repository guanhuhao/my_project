// 2019-1-15 简单搜索 Fliptile.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int mapp[20][20];
int n, m;
int out;
int out2[20][20];
bool check(int x, int y) {
	return x >= 0 && x < n&&y >= 0 && y < m;
}
void rever(int x, int y) {
	int dx[4] = { 0,0,1,-1 },
		dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (check(xx, yy)) mapp[xx][yy] = !mapp[xx][yy];
	}

}
void dfs(int deep,int cnt,int ans[][20]) {
	if (deep >= m) return;
	dfs(deep + 1,cnt,ans);
	rever(0,deep);
	ans[0][deep] = 1;
	dfs(deep + 1,cnt+1,ans);
	ans[0][deep] = 0;
	rever(0,deep);

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (mapp[i][j] == 1) {
				rever(i + 1, j);
				ans[i + 1][j]=1;
				cnt++;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (mapp[n - 1][i] == 1) {
			for (int i = 1; i < n; i++)
				for (int j = 0; j < m; j++)
					if (ans[i][j] == 1)
						rever(i, j);
			return;
		}
	}
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ans[i][j] == 1)
				rever(i, j);
	if (cnt < out) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)out2[i][j] = ans[i][j];
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m) {
		out = 10000;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> mapp[i][j];
		}
		int ans[20][20];
		memset(ans, 0, sizeof(ans));
		dfs(0,0,ans);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << out2[i][j] << " ";
			}
			cout << endl;
		}
	}
    return 0;
}

