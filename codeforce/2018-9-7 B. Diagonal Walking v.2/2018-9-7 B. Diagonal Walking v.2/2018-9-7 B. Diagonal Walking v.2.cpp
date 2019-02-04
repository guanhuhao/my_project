// 2018-9-7 B. Diagonal Walking v.2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	ll x, y,k;
	ll ans = 0;
	while (n--) {
		cin >> x >> y >> k;
		x = max(x, -x);
		y = max(y, -y);
		ans = min(x, y);
		x -= ans;
		y -= ans;
		k -= ans;
		if ( x + y > k) cout << -1 << endl;
		else {
			if ((x + y) % 2 == 1) {
				ans += k - 1;
			}
			else {
				if (k % 2 == 1) {
					ans--;
					k--;
					ans += k;
				}
				else ans += k;
			}
			cout << ans << endl;
		}
	}
    return 0;
}

