// 2018-7-22 C.Persona5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int mod = 1000000007;
ll a[maxn];
ll qs(ll a, ll b) {
	ll ans = 1;
	ll base = a;
	while (b != 0) {
		if (b % 2 == 1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		b /= 2;
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n) {
		ll sum = 0;
		ll ans = 0;
		ans = 1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 1; i <= sum; i++) {
			ans = (i*ans) % mod;
		}
		for (int i = 0; i < n; i++) {
			//cout << ans << endl;
			ll tem = 1;
			for (int j = 1; j <= a[i]; j++) tem = (tem*j)%mod;
			ans = (ans*qs(tem, mod - 2)) % mod;
		}
		cout << ans<<endl;
	}
    return 0;
}

