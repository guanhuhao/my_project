// 2018-7-3 A. Polycarp's Pockets.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[110];
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		a[tem]++;
	}
	int ans = 0;
	for (int i = 0; i <= 100; i++) {
		ans = max(ans, a[i]);
	}
	cout << ans;
    return 0;
}

