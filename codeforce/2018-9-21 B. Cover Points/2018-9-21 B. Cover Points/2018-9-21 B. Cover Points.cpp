// 2018-9-21 B. Cover Points.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		ans = max(ans, tem1 + tem2);
	}
	cout << ans << endl;
    return 0;
}

