// 2018-7-24 K - Lake Counting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int n, m;
int temx[8] = { 0,0,1,1,1,-1,-1,-1 };
int temy[8] = { 1,-1,1,-1,0,1,-1,0 };
bool ok(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < m);
}
void dfs(int x, int y) {
	a[x][y] = '.';
	for (int i = 0; i < 8; i++) {
		
		if (ok(x + temx[i],y + temy[i])&&a[x + temx[i]][y + temy[i]] == 'W') dfs(x + temx[i], y + temy[i]);
	}
	return;
}
int main()
{
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'W') {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
    return 0;
}

