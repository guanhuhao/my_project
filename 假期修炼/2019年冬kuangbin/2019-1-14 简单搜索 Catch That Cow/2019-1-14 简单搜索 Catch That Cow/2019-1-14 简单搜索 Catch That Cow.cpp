// 2019-1-14 简单搜索 Catch That Cow.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1e5 + 10;
int ans[maxn];
queue<int> que;
bool check(int a) {
	return a >= 0 && a < maxn&&ans[a] == -1;
}
void bfs(int s) {
	ans[s] = 0;
	que.push(s);
	while (!que.empty()) {
		int top = que.front();
		que.pop();
		if (check(top + 1)) {
			ans[top + 1] = ans[top] + 1;
			que.push(top + 1);
		}
		if (check(top - 1)) {
			ans[top - 1] = ans[top] + 1;
			que.push(top - 1);
		}
		if (check(top * 2)) {
			ans[top * 2] = ans[top] + 1;
			que.push(top * 2);
		}
	}
}
int main()
{
	int s, e;
	while (cin >> s >> e) {
		memset(ans, -1, sizeof(ans));
		bfs(s);
		cout << ans[e] << endl;
	}
    return 0;
}

