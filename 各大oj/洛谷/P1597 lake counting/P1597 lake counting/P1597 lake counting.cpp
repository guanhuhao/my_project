// P1597 lake counting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int m, n;
int ans = 0;
char a[105][105];
int diri[8] = { -1,-1,-1,0,0,1,1,1 }, dirj[8] = { -1,0,1,-1,1,-1,0,1 };
void dp(int y, int x) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (y + diri[i] > -1 && y + diri[i]<m&&x + dirj[j]>-1 && x + dirj[j] < n) {
				if (a[y + diri[i]][x + dirj[j]] == 'W') {
					a[y + diri[i]][x + dirj[j]] = '.';
					dp(y + diri[i], x + dirj[j]);
				}
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'W') {
				a[i][j] = '.';
				ans++;
				dp(i, j);
			}
		}
	}
	cout << ans << endl;
    return 0;
}

