// 2018-9-7 D. Slime.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 10;

int main()
{
	int n;
	int flag1=0, flag2=0;
	ll ans = 0;
	ll mini = 1e12;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		ll tem;
		cin >> tem;
		if (tem > 0) flag1 = 1;
		if (tem < 0) flag2 = 1;
		ans += abs(tem);
		mini = min(mini, abs(tem));
	}
	
	if (n!=1&&(flag1==0||flag2==0)) {
		ans -= 2 * mini;
		cout << ans << endl;
	}
	else cout << ans << endl;
    return 0;
}

