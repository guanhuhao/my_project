// 2018-11-17 sum kind of problem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll tem1,tem2;
		ll ans1, ans2, ans3;
		cin >> tem1>>tem2;
		ans1 = (1 + tem2)*tem2 / 2;
		ans2 = tem2*tem2;	
		ans3 = (2 * tem2 + 2)*tem2 / 2;
		cout << tem1 << " " << ans1 << " " << ans2 << " " << ans3 << endl;
	}
    return 0;
}

