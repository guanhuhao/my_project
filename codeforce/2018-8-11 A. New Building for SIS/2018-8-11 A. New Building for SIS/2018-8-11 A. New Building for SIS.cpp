// 2018-8-11 A. New Building for SIS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, h,a,b,k;
	ios::sync_with_stdio(false);
	cin >> n >> h >> a >> b>>k;
	for (int i = 0; i < k; i++) {
		ll x1, y1, x2, y2;
		ll ans = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		if (y1 > b) ans = y1 - b+abs(y2-b);
		else if (y1 < a) ans = a - y1+abs(y2-a);
		else ans =abs(y1 - y2);
		if (x1 == x2  ) ans = abs(y1-y2);
		ans += abs(x1 - x2);
		cout << ans << endl;
	}
    return 0;
}

