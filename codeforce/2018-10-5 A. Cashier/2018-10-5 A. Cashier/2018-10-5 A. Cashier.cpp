// 2018-10-5 A. Cashier.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, l, a;
	int ans = 0;
	cin >> n >> l >> a;
	int beg=0;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		ans += (tem1 - beg) / a;
		beg = tem2+tem1;
	}
	ans += (l - beg) / a;
	cout << ans << endl;
    return 0;
}

