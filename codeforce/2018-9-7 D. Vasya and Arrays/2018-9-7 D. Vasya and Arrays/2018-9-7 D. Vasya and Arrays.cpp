// 2018-9-7 D. Vasya and Arrays.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 3e5 + 10;
ll n, m;
ll a[maxn], b[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	int i = 0, j = 0;
	long long ans = 0;
	while (i < n&&j < m) {
		if (a[i] == b[j]) {
			i++;
			j++;
			ans++;
		}
		if (a[i] > b[j]) {
			b[j + 1] += b[j];
			j++;
		}
		if (a[i] < b[j]) {
			a[i + 1] += a[i];
			i++;
		}
	}
	if (i == n&&j == m) cout << ans << endl;
	else cout << -1 << endl;
    return 0;
}

