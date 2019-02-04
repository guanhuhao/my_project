// 2018-7-13 B. Turn the Rectangles.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
	int n;
	pair<int, int> a[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	a[0].first = max(a[0].first, a[0].second);
	for (int i = 1; i < n; i++) {
		if (a[i - 1].first >= max(a[i].first, a[i].second)) a[i].first = max(a[i].first, a[i].second);
		else a[i].first = min(a[i].first, a[i].second);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first < a[i + 1].first) ans = 1;
	}
	ans ? cout << "NO" << endl : cout << "YES" << endl;
    return 0;
}

