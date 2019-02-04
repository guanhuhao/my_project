// 2018-10-13 B。Cities.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
ll a[maxn];
bool cmp(ll a, ll b) {
	return a < b;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		ll ans = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		sort(a, a + n, cmp);
		for (int i = 1; i < n; i++) {
			ans += a[0] + a[i];
		}
		cout << ans << endl;
	}
    return 0;
}

