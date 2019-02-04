// 2018-8-17 A.Single Wildcard Pattern.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	string a, b;
	cin >> n >> m;
	cin >> a >> b;

	int flag = 0;
	for (int i = 0; i < n&&i<m; i++) {
		if (a[i] == '*') break;
		if (a[i] != b[i]) {
			flag = 1;
			break;
		}
	}
	for (int i = 0; i <n; i++) {
		int tema = a.size() - 1 - i;
		int temb = b.size() - 1 - i;
		if (tema < 0 || temb < 0) break;
		if (a[tema] == '*') break;
		if (a[tema] != b[temb]) {
			flag = 1;
			break;
		}
	}
	int flag2 = 0;
	for (int i = 0; i < a.size(); i++) if (a[i] == '*') flag2=1;
	if (flag2) {
		if (flag == 1 || n - 1 > m) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	else {
		if (flag == 1 || n != m) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
    return 0;
}

