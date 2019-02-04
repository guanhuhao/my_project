// 2018-8-25 D. Concatenated Multiples.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll, ll> m;
const int maxn = 2e5 + 10;
ll a[maxn];

int main()
{
	ios::sync_with_stdio(false);
	ll n, mod;
	cin >> n >> mod;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] %= mod;
		m[a[i]]++;
	}
	ll ans = 0;
	for (auto i = m.begin(); i != m.end(); i++) {
		int tem = mod - (((*i).first*10)%mod);
		cout << "text:" << (*i).first << " " << tem<<endl;
		if (tem == (*i).first) ans += (*i).second*(m[tem] - 1);
		else ans += (*i).second*m[tem];
	}
	cout << ans << endl;
    return 0;
}

