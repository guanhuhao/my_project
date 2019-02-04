// 2018-7-13 C. Reorder the Array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	int n;
	priority_queue<int, vector<int>, greater<> > que;
	pair<int,int> a[maxn];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
		a[i].first = i;
		que.push(a[i].second);
	}
	sort(a, a + n, cmp);
	int i = 0;
	while (!que.empty()) {
		while (!que.empty() && a[i].second >= que.top()) {
			que.pop();
		}
		if (!que.empty()&&a[i].second < que.top())
		{
			i++;
			que.pop();
		}
	}
	cout << i << endl;
	return 0;
}

