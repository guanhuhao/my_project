// 2018-7-16 A. Adjacent Replacements.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[1010];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		if (tem % 2 == 0) a[i] = tem - 1;
		else a[i] = tem;
	}
	for (int i = 0; i < n; i++) cout << a[i]<<" ";
	cout << endl;
    return 0;
}

