// 2018-9-21 A. Little C Loves 3 I.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 3 == 0) {
		cout << 1 << " " << 1 << " " << n - 2 << endl;
	}
	else cout << 1 << " " << 2 << " " << n - 3 << endl;

    return 0;
}

