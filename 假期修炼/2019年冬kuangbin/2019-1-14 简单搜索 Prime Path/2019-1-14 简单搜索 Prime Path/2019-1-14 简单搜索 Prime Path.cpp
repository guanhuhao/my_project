// 2019-1-14 简单搜索 Prime Path.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int isprime[10005];
void init() {
	memset(isprime, 0, sizeof(isprime));
	for (int i = 1000; i < 10005; i++) {
		int flag = 0;
		for (int j = 2; j <= sqrt(i) + 1; j++) {
			if (i%j == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) isprime[i] = 1;
	}
}
int ans[10005];
queue<int> que;
bool check(int a) {
	return isprime[a] && ans[a] == -1;
}
void bfs(int begin) {
	memset(ans, -1,sizeof(ans));
	ans[begin] = 0;
	que.push(begin);
	while (!que.empty()) {
		int top = que.front();
		que.pop();
		int aa[4] = { top % 10,top / 10 % 10,top / 100 % 10, top / 1000 };
		int ji = 1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 3&&j==0) continue;
				if (aa[i] == j) continue;
				if (check(top - (aa[i] - j)*ji)) {
					ans[top - (aa[i] - j)*ji] = ans[top] + 1;
					que.push(top - (aa[i] - j)*ji);
				}
			}
			ji *= 10;
		}
	}
}
int main()
{
	init();
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		bfs(a);
		if (ans[b]!=-1) cout << ans[b]<<endl;
		else cout << "Impossible" << endl;
	}
    return 0;
}

