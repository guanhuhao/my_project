// 2018-6-23 A. If at first you.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, c, n;
	int ans = 0;;
	cin >> a >> b >> c >> n;
	ans = n - (a + b - c);
	if (ans < 1||a<c||b<c) cout << -1<<endl;
	else cout << ans<<endl;
    return 0;
}

