// 2018-6-17 B. Dong先生的计算题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		if (n % 10 != 0) n = n - 1;
		else n = n / 10;
	}
	cout << n << endl;
    return 0;
}

