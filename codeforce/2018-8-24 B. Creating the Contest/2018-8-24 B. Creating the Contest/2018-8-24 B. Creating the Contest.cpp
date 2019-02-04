// 2018-8-24 B. Creating the Contest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	memset(a, 0, sizeof(a));
	int n;
	long long ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	long long tem = 1;
	for (int i = 0; i < n - 1; i++) {
		if (2 * a[i] >= a[i + 1]) tem++;
		else {
			ans = max(tem, ans);
			tem = 1;
		}
		ans = max(tem, ans);
	}
	cout << ans << endl;
	return 0;
}

