// 2018-7-1 B. Cutting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	int a[110];
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	int ji=0, ou = 0;
	priority_queue<int, vector<int>, greater<int>> que;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) ou++;
		else ji++;
		if (ji == ou&&i != n - 1) que.push(abs(a[i] - a[i + 1]));
	}
	int _count = 0;
	int ans = 0;
	while (!que.empty()) {
		_count += que.top();
		que.pop();
		if (_count > k) break;
		ans++;
	}
	cout << ans <<endl;
    return 0;
}

