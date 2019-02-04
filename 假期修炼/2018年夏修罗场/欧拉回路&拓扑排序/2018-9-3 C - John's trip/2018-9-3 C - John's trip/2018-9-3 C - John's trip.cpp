// 2018-9-3 C - John's trip.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct EDGE {
	int u, v;
}edge[5000];
int used[5000];
int fat[50];
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
priority_queue<int,vector<int>,cmp> que[50];
vector<int> ans;
void init() {
	for (int i = 0; i < 50; i++) while (!que[i].empty()) que[i].pop();
	for (int i = 0; i < 50; i++) fat[i] = i;
	memset(used, 0, sizeof(used));
	ans.clear();
}
int findf(int a) {
	return a == fat[a] ? a : fat[a]=findf(fat[a]);
}
void uni(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	fat[x] = fat[y];
}
int main()
{
	int tem1, tem2, tem3;
	while (cin >> tem1 >> tem2) {
		init();
		if (tem1 == 0 && tem2 == 0) break;
		cin >> tem3;
		edge[tem3].u = tem1;
		edge[tem3].v = tem2;
		que[tem1].push(tem3);
		que[tem2].push(tem3);
		while (cin >> tem1 >> tem2) {
			if (tem1 == 0 && tem2 == 0) break;
			cin >> tem3;
			edge[tem3].u = tem1;
			edge[tem3].v = tem2;
			que[tem1].push(tem3);
			que[tem2].push(tem3);
			uni(tem1, tem2);
		}

		int flag = 0;
		for (int i = 0; i < 50; i++) {
			if (que[i].size() % 2 != 0) flag = 1;
		}
		int cnt = 0;
		for (int i = 0; i < 50; i++) {
			if (que[i].size() && fat[i] == i) cnt++;
		}
		if (cnt > 1) flag = 1;

		ans.push_back(1);
		que[edge[1].u].pop();
		que[edge[1].v].pop();
		used[1] = 1;
		int pos = que[edge[1].u].top() < que[edge[1].v].top() ? edge[1].u : edge[1].v;
		while (!que[pos].empty()) {
			int top = que[pos].top();
			que[pos].pop();
			if (used[top]) continue;
			if (edge[top].u == edge[top].v) {
				used[edge[top].u] = 1;
				used[edge[top].v] = 1;

			}
			ans.push_back(top);
			pos = edge[top].u + edge[top].v - pos;
			used[top] = 1;
		}
		cout << "ans:";
		if (flag == 1) cout << "Round trip does not exist." << endl;
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (i == 0) cout << "1";
				else cout << " " << ans[i];
			}
			cout << endl;
		}
	}
    return 0;
}

