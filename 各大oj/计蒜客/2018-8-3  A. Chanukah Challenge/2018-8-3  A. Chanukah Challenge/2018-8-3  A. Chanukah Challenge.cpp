// 2018-8-3  A. Chanukah Challenge.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tem,tem2;
		cin >> tem>>tem2;
		cout << tem << " " << (1 + tem2)*tem2 / 2 + tem2 << endl;
	}
    return 0;
}

