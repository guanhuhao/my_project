// 2018-9-2 A. Packets.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	int ans = 0;
	cin >> a;
	while (a) {
		ans++;
		a /= 2;
	}
	cout << ans << endl;
    return 0;
}

