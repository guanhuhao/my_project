// 2018-8-18 A. Palindromic Twist.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		int flag = 0;
		for (int i = 0; i < n / 2; i++) {
			if (str[i] + 1 == str[n - 1 - i] + 1 || str[i] + 1 == str[n - 1 - i] - 1 || str[i] - 1 == str[n - 1 - i] + 1 || str[i] - 1 == str[n - 1 - i] - 1) continue;
			flag = 1;
		}
		if (flag == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
    return 0;
}

