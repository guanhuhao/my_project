// 2018-9-7 C. Classy Numbers.cpp: 定义控制台应用程序的入口点。
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
		ll l, r;
		ll cntl, cntr;
		cin >> l >> r;
		if (l <= 999) cntl = l;
		else {
			for (ll i = 1; i <= 9; i++) {
				ll tem = i;
				for (ll j = 0; j <= 18; j++) {
					tem *= 10;
					if (tem > 1e18||tem<0) break;
					if (tem >= l&&tem <= r) cntl++;
				}
			}
			for (ll i = 11; i <= 99; i++) {
				if (i % 10 == 0) continue;
				for()
			}
		}
	}
    return 0;
}

