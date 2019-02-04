// 2018-6-10 B. Micro-World.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[2*maxn] = {0};
int _count[maxn] = { 0 };
int main()
{
	int n, k;
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		a[tem] = 1;
		_count[tem]++;
	}
	for (int i = 1; i < maxn; i++) a[i] = a[i - 1] + a[i];

	int ans = n;
	for (int i = 0; i < maxn; i++) {
		if (a[i + k] > a[i]) ans-=_count[i];
	}

	cout << ans << endl;
    return 0;
}

