// 2018-7-22 B.Set.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[101];
ll b[101];
ll ans = 0;
ll dp(int l, int r) {
	ll tem = 0;
	for (int i = l; i <= r; i++) {
		tem += dp(i + 2, r);
	}
	return tem;
}
int main()
{
	for (int i = 1; i <= 100; i++) a[i] = i*i;
	ll n;
	while (cin >> n) {
		ans = 0;
		b[n] = a[n];
		b[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 1; i--) {
			ll tem = 0;
			for (int j = i + 2; j <= n; j++) {
				tem += b[j];
			}
			b[i] = i*i*(tem + 1);
		}
		//	for (int i = 1; i <= n; i++) cout << b[i] << endl;
		for (int i = 1; i <= n; i++) ans += b[i];
		cout << ans << endl;
	}
	return 0;
}

