// 2018-7-28 B - Cash Machine.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int ans[120000];
vector<int> v;
void init() {
	memset(ans, -1, sizeof(ans));
	v.clear();
}
int dp(int n, int cash) {
	if (n < 0) return 0;
	if (ans[cash] != -1) return ans[cash];
	else {
		if (cash - v[n] < 0) return ans[cash] = dp(n - 1, cash);
		return ans[cash] = max(dp(n - 1, cash), dp(n - 1, cash - v[n]) + v[n]);
	}
}
int main()
{
	int cash, n;
	while (cin >> cash >> n) {
		init();
		for (int i = 0; i < n; i++) {
			int num, mian;
			cin >> num >> mian;
			int tem = 1;
			while (tem < num) {
				v.push_back(tem*mian);
				//	cout << tem << " ";
				num -= tem;
				tem *= 2;
			}
			if (num) v.push_back(num*mian);
			//cout <<num<< endl;
		}
		ans[0] = 0;
		cout << dp(v.size() - 1, cash) << endl;

		//cout << v.size() << " " << cash << " " << ans[v.size() - 1][cash] << endl;
	}
	return 0;
}

