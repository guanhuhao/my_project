// 2018-6-21 A. Mishka and Contest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
deque<int> a;
int main()
{
	int n, k;
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		a.push_back(tem);
	}
	while (!a.empty()&&a.front() <= k) {
		ans++;
		a.pop_front();
	}
	while (!a.empty() && a.back() <= k) {
		ans++;
		a.pop_back();
	}
	cout << ans << endl;
    return 0;
}

