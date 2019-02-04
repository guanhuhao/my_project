// 2019-1-14 简单搜索 Find The Multiple.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>

using namespace std;
unsigned long long ans;
int n;
void dfs(int deep,unsigned long long date) {
	if (deep >= 20) return;
	if (date%n == 0) {
		ans = date;
		return;
	}
	if(!ans)dfs(deep + 1, date * 10);
	if(!ans)dfs(deep + 1, date * 10 + 1);
}

int main()
{
	while (cin >> n&&n) {
		ans = 0;
		dfs(0, 1);
		cout << ans << endl;
	}
    return 0;
}

