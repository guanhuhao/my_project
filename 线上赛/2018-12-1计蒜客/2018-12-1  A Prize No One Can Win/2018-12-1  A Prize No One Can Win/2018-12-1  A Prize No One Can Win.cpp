// 2018-12-1  A Prize No One Can Win.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
	int n, m;
	int a[maxn];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 1;
	for (int i = 1; i < n; i++) if (a[i] + a[i - 1] <= m) ans++; else break;
	cout << ans << endl;
    return 0;
}

