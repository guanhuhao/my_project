// 2018-9-23 B. Vasya and Cornfield.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int x[110], y[110];
int main()
{
	int n, d;	
	int m;
	cin >> n >> d;	
	cin >> m;
	for (int i = 0; i < m; i++) cin >> x[i] >> y[i];

	for (int i = 0; i < m; i++) {
		int flag = 0;
		if (x[i] + y[i] - d < 0)flag = 1;
		if (x[i] + y[i] > n - d + n) flag = 1;
		if (-x[i] + y[i] - d > 0) flag = 1;
		if (-x[i] + y[i] + d < 0)flag = 1;
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
    return 0;
}

