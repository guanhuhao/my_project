// 2018-9-20 B. Relatively Prime Pairs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	for (ll i = l; i + 1 <= r; i += 2) {
		cout << i << " " << i + 1 << endl;
	}
    return 0;
}

