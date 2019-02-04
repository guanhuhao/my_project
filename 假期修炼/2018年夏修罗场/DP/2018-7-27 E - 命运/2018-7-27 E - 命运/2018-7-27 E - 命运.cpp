// 2018-7-27 E - 命运.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[25][1050];
int ans[25][1050];

int n, m;
const int inif = -(int)1e8;
void init() {
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 1050; j++)
			ans[i][j] = inif;
}
int dp(int x, int y) {
	if (ans[x][y] == inif) {
		int maxi = inif;
		if(x-1>0)maxi = max(maxi, dp(x - 1, y));
		if(y-1>0)maxi = max(maxi, dp(x, y - 1));
		for (int i = 2; i <=y; i++) {
			if (y%i == 0) maxi = max(maxi, dp(x, y / i));
		}
		return ans[x][y] =a[x][y]+ maxi;
	}
	else return ans[x][y];
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		}

		ans[1][1] = a[1][1];
		dp(n , m );
		/*cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << ans[i][j] << " ";
			cout << endl;
		}*/
		cout << ans[n][m] << endl;
	}
    return 0;
}

