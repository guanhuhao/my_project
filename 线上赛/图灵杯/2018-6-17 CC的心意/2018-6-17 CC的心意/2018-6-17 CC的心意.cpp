// 2018-6-17 CC的心意.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[20];
	int len;
	cin >> a;
	len = strlen(a);
	for (int i = 0; i < len; i++)a[i] = a[i] - '0';
	int ans1, ans2, ans3, ans4;
	for (int i = len; i > -1; i--) {
		if (a[i] == 5 && (i != 0 || a[i - 1] != 0)) {
			ans1 = len - i;
			break;
		}
	}
	for (int i = len; i > -1; i--) {
		if (a[i] == 2 && (i != 0 || a[i - 1] != 0)) {
			ans1 = ans1 + len - i - 1;
		}
	}
    return 0;
}

