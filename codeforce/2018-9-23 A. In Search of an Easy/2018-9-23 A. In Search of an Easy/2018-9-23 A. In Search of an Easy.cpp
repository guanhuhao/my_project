// 2018-9-23 A. In Search of an Easy.cpp: 定义控制台应用程序的入口点。
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
		int tem;
		cin >> tem;
		ans = max(ans, tem);
	}
	if (ans == 1) cout << "HARD" << endl;
	else cout << "EASY" << endl;
    return 0;
}

