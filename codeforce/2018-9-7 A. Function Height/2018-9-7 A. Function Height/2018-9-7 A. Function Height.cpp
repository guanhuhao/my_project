// 2018-9-7 A. Function Height.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, k;
	ll ans = 0;
	cin >> n >> k;
	ans = k/n;
	if (k%n != 0) ans++;
	cout << ans << endl;
    return 0;
}

