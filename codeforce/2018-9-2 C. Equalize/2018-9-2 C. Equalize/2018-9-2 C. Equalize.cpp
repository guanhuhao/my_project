// 2018-9-2 C. Equalize.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int cost = 0;
	string a, b;
	cin >> n;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (a[i + 1] == b[i] && a[i] == b[i + 1]) i++;
			cost++;
		}
	}
	cout << cost<<endl;
    return 0;
}

