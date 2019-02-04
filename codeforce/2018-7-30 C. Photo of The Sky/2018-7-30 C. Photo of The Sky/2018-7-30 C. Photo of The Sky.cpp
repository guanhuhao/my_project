// 2018-7-30 C. Photo of The Sky.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
int main()
{
	int n;
	ll x1,x2,y1,y2;

	cin >> n;
	for (int i = 0; i < 2 * n; i++)cin >> a[i];
	sort(a, a + 2 * n);
	x1 = a[0]; x2 = a[n - 1];
	y1 = a[n]; y2 = a[2 * n - 1];

	ll ans = (x2 - x1)*(y2 - y1);
	for (int i = 1; i < n; i++) ans = min(ans, (a[i + n - 1] - a[i])*(a[2 * n - 1]-a[0]));
	cout << ans << endl;
    return 0;
}

