// 2018-6-11 B. A Tide of Riverscape.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	string a;
	cin >> n >> k;
	cin >> a;
	int flag = 0;
	for (int i = 0; i + k < n; i++) {
		if ((a[i] == '0' || a[i] == '1') && a[i] == a[i + k]) continue;
		flag = 1;
		if (a[i] == a[i + k] && a[i] == '.') {
			a[i] = '0';
			a[i] = '1';
		}
		else if (a[i] == '.') a[i] = (a[i + k] - '0' + 1) % 2 + '0';
		else if (a[i + k] == '.')a[i + k] = (a[i] - '0' + 1) % 2 + '0';
		for (int j = 0; j < n; j++) a[j] == '.' ? a[j] = '0' : 0;
		break;
	}
	flag == 0 ? cout << "No" << endl : cout << a<<endl;
    return 0;
}

