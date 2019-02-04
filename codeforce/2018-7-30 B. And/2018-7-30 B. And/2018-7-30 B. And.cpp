// 2018-7-30 B. And.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int main()
{
	int n, x;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	cin >> n >> x;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		a[tem]++;
		b[(tem & x)]++;
		if (a[tem] == 2) flag1 = 1;
		if (b[(tem & x)] == 2) flag2 = 1;
	}
	for (int i = 0; i < maxn; i++) {
		if (a[i] > 0 && b[i] > 0) {
			//cout << a[i] << " "<<b[i] << endl;
			if ((i & x) == i && b[i] - a[i] == 0) continue;
			flag3 = 1;
			break;
		}
	}
	if (flag1 == 1) cout << 0 << endl;
	else if (flag3 == 1) cout << 1 << endl;
	else if (flag2 == 1) cout << 2 << endl;
	else cout << -1 << endl;

    return 0;
}

