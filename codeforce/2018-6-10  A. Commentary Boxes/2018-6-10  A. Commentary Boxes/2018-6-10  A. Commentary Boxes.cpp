// 2018-6-10  A. Commentary Boxes.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m, a, b;
	long long ans = 0;
	cin >> n >> m >> a >> b;
	ans = min(b*(n%m), a*(m - n%m));
	cout << ans << endl;
    return 0;
}

