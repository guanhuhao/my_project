// 2018-8-24 A. Many Equal Substrings.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	string str;
	cin >> n >> m;
	cin >> str;
	int flag = 0;
	for (int i = 1; i < n; i++) {
		int j = i;
		int k = 0;
		while (j < n) {
			if (str[j] != str[k]) break;
			j++;
			k++;
		}
		if (j == n) {
			flag = n - i;
			i = n;
		}
	}
	//cout << "text:" << flag << endl;
	cout << str;
	for (int i = 1; i < m; i++) {
		for (int j = flag; j < n; j++) {
			cout << str[j];
		}
	}
	cout << endl;
    return 0;
}

