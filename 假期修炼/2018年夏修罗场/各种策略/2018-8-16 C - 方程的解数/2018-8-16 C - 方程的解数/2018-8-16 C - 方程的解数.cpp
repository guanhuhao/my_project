// 2018-8-16 C - 方程的解数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int mod = 10000007;	
int n, m;
int k[10], p[10];
int ans = 0;
int qpow(int a, int b) {
	int base = a;
	int ans = 1;
	while (b != 0) {
		if (b % 2 == 1) ans *= base;
		base *= base;
		b /= 2 ;
	}
	return ans;
}
struct num {
	int acout, value;
}has[mod];

int serch(int y) {
	int y2 = ((y%mod) + mod) % mod;
	while (has[y2].acout != 0 && has[y2].value != y) {
		y2++;
		if (y2 >= mod)y2 -= mod;
	}
	return y2;
}
void insert(int y) {
	int temp = serch(y);
	has[temp].acout++;
	has[temp].value = y;
	return;
}
void dfs1(int x, int y) {
	if (x == n / 2) {
		insert(y);
	}
	else {
		for (int i = 1; i <= m; i++)
			dfs1(x + 1, y + k[x] * qpow(i, p[x]));
	}
}
void dfs2(int x, int y) {
	if (x == n) {
		y = -y;
		if(has[serch(y)].value==y)ans += has[serch(y)].acout;
	}
	else {
		for (int i = 1; i <= m; i++)
			dfs2(x + 1, y + k[x] * qpow(i, p[x]));
	}
}
int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> k[i] >> p[i];
	
	dfs1(0, 0);
	dfs2(n / 2, 0);
	cout << ans << endl;
    return 0;
}

