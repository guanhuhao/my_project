// 2018-8-11 B. Badge.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[1010];
int ans[1010];
int main()
{
	int n;
	memset(a, 0, sizeof(a));
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		memset(ans, 0, sizeof(ans));
		int p = i;
		ans[p] = 1;
		while (ans[p] < 2) {
			ans[a[p]]++;
			p = a[p];
		}
		cout << p << " ";
	}
	cout << endl;

    return 0;
}

