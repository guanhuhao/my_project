// 2018-5-30 fence repair.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstdio>
bool cmp(int a, int b) {
	return a < b;
}
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int>> a;
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tem;
		scanf("%d", &tem);
		a.push(tem);
	}
	while (!a.empty()) {
		int tem1 = a.top();
	//	cout << tem1 << endl;
		a.pop();
		if (a.empty()) break;
		int tem2 = a.top();
		a.pop();
		ans = ans + tem1 + tem2;
		a.push(tem1 + tem2);
	}
	cout << ans << endl;
    return 0;
}

