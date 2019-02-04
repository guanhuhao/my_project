// 2018-8-1 E.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
char a[200][200];
int vis[200][200];
struct star
{
	int x, y, l;
	star(int a, int b, int c) { x = a, y = b, l = c; }
	star() { }
};
int n, m;
vector<star>ha;
void serch(int x, int y)
{
	int z = 0, yy = 0, s = 0, d = 0;
	while (++z&&y - z >= 0 && a[x][y - z] == '*');
	while (++yy&&yy + y <= m&&a[x][yy + y] == '*');
	while (++s&&x + s <= n&&a[x + s][y] == '*');
	while (++d&&x - d >= 0 && a[x - d][y] == '*');
	int minn = 999999;
	minn = min(z, yy);
	minn = min(minn, s);
	minn = min(minn, d);
	if (minn - 1 >= 1)
	{
		ha.push_back(star(x, y, minn - 1));
		for (int i = 0; i <= minn - 1; i++)
		{
			vis[x + i][y] = 1;
			vis[x - i][y] = 1;
			vis[x][y + i] = 1;
			vis[x][y - i] = 1;
		}
	}
}

void solve() {
	while (cin >> n >> m)
	{
		ha.clear();
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (a[i][j] == '*') serch(i, j);
			}
		int flag = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (a[i][j] == '*'&&vis[i][j] == 0) { flag = 1; break; }
			}
		if (flag) cout << -1 << endl;
		else {
			cout << ha.size() << endl;
			for (int i = 0; i<ha.size(); i++)
			{
				printf("%d %d %d\n", ha[i].x, ha[i].y, ha[i].l);
			}

		}

	}
}
int main()
{
	solve();
	return 0;
}