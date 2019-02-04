// 2018-7-24 A - Tempter of the Bone (2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n, m, t,w,mn;	
int xs = 0, ys = 0;
int xe = 0, ye = 0;
char a[8][8];
int tema[4] = { 0,0,-1,1 };
int temb[4] = { 1,-1,0,0 };
int flag = 0;
bool ok(int x, int y) {
	return (x >= 0 && x < n&&y >= 0 && y < m);
}
void dfs(int x, int y, int bu) {
	//cout << x << "  " << xe<<"  "<<y<<"  "<<ye << endl;
	if (bu>t) return ;
	if (x == xe && y == ye&&t == bu) { flag = 1; return; }
	for (int i = 0; i < 4; i++) {
		if (flag) return;
		if (ok(x + tema[i], y + temb[i])&& a[x + tema[i]][y + temb[i]]!='X') {
			a[x + tema[i]][y + temb[i]] = 'X';
			dfs(x + tema[i], y + temb[i], bu + 1);
			a[x + tema[i]][y + temb[i]] = '.';
		}
	}
	return;
}
int main()
{

	while (cin >> n >> m >> t) {
		w = 0;
		flag = 0;
		if (!n && !m && !t) break;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 'X') w++;
				if (a[i][j] == 'S')xs = i, ys = j;
				if (a[i][j] == 'D') xe = i, ye = j;
			}
		}	

		mn = m*n - w;	
		if ((xs + ys + xe + ye) % 2 != t % 2||mn<t) cout << "NO" << endl; 
		else {
			a[xs][ys] = 'X';
			dfs(xs, ys, 0);
			if (flag) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
    return 0;
}

