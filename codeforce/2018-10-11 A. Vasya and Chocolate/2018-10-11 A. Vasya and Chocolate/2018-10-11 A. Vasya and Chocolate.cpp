// 2018-10-11 A. Vasya and Chocolate.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		ll ans=0;
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ans += a / d;
		ans += c*(a / d / b);
		cout << ans << endl;
	}
    return 0;
}

