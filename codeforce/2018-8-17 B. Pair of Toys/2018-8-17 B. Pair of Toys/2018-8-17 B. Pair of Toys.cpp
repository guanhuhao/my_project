// 2018-8-17 B. Pair of Toys.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, k;
	ll ans=0;
	cin >> n >> k;
	if (k <= n + 1) {
		ans = (k-1) / 2;
	}
	else if(k<=n+n-1) {
		ans = (n - (k - n) + 1) / 2;
	}
	else ans = 0;
	cout << ans << endl;
    return 0;
}

