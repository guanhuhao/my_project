// 2018-9-2 D. Bicolorings.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll a[1010][4][2010];
int main()
{
	ll col, k;

	while (cin >> col >> k) {
		memset(a, 0, sizeof(a));
		a[1][0][1] = 1;
		a[1][1][1] = 1;
		a[1][2][2] = 1;
		a[1][3][2] = 1;
		for (int i = 2; i <= col; i++) {
			for (int j = 1; j < 2005; j++) {
				a[i][0][j] = (a[i - 1][1][j - 1] + a[i - 1][0][j] + a[i - 1][2][j] + a[i - 1][3][j]) % mod;
				a[i][1][j] = (a[i - 1][0][j - 1] + a[i - 1][1][j] + a[i - 1][2][j] + a[i - 1][3][j]) % mod;
				//if (j == 1) cout <<"text:"<< a[i - 1][3][-1] << endl;
				a[i][2][j] = (a[i - 1][1][j - 1] + a[i - 1][0][j - 1] + a[i - 1][3][j - 2] + a[i - 1][2][j]) % mod;
				a[i][3][j] = (a[i - 1][1][j - 1] + a[i - 1][0][j - 1] + a[i - 1][2][j - 2] + a[i - 1][3][j]) % mod;
			}
		}
		ll ans = 0;
		ans = (a[col][0][k] + a[col][1][k] + a[col][2][k] + a[col][3][k]) % mod;
		cout << ans << endl;
	}
    return 0;
}

