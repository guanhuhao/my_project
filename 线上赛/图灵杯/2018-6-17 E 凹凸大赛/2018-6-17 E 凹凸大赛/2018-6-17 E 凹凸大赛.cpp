// 2018-6-17 E 凹凸大赛.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int maxn = (int)2e5 + 10;
int main()
{
	int n, k;
	int a[maxn];
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (k == n)cout << a[k - 1] << endl;
	else if (k == 0 && a[0] != 1) cout << "1" << endl;
	else if (k == 0 && a[0] == 1)cout << -1 << endl;
	else if (k < n&&a[k] == a[k - 1])cout << "-1"<<endl;
	else cout << a[k-1] << endl;

	return 0;
}

