// 2018-7-26 B. Planning The Expedition.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < m; i++) {
		int tem;
		cin >> tem;
		a[tem]++;
	}
	sort(a, a + 105, cmp);
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		int tem = 0;
		for (int j = 0; j <= 100; j++) {
			tem += a[j] / i;
		}
		if (tem >= n) ans = i;
	}
	cout << ans << endl;
    return 0;
}

