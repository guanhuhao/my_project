// 2018-9-17 D. Petya and Array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, t;
ll a[maxn];
int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> t;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	int l = 0 , r=1;
	int ans = 0;
	while (r <= n) {
		if (l == r) r++;
		if (a[r] - a[l] > t) l++;
		else {
			ans++;
			while()
			cout << "test:" << l << " " << r << endl;
			r++;

		}
	}
	cout << ans << endl;
    return 0;
}

