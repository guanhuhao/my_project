// 2018-9-4 C - John's trip.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct Edge {
	int u, v;
}edge[2000];
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
priority_queue<int, vector<int>, cmp> v[50];
int used[2000];
int fat[50];
int cnt;
void init() {
	memset(used, 0, sizeof(used));
	cnt = 0;
	for (int i = 0; i < 50; i++) {
		fat[i] = i;
		while(!v[i].empty())v[i].pop();
	}
}
int findf(int a) {
	return a == fat[a] ? a : fat[a] = findf(fat[a]);
}
void uni(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	fat[x] = y;
}
bool pending() {
	int flag = 0;
	for (int i = 0; i < 50; i++) {
		if (v[i].size() % 2 != 0) flag = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 50; i++) {
		if (v[i].size() != 0 && fat[i] == i)
			cnt++;
	}
	return !(flag == 1 || cnt > 1);
}
void dfs(int sta) {
	while (used[v[sta].top()] == 1) v[sta].pop();
}
int main()
{
	ios::sync_with_stdio(false);
	int tem1, tem2, tem3;
	while (cin >> tem1 >> tem2&&tem1) {
		cin >> tem3;
		init();
		edge[tem3] = { tem1,tem2 };
		v[tem1].push(tem3);
		v[tem2].push(tem3);
		uni(tem1, tem2);
		cnt++;
		while (cin >> tem1 >> tem2&&tem1) {
			cin>>tem3;
			edge[tem3] = { tem1,tem2 };
			v[tem1].push(tem3);
			v[tem2].push(tem3);
			uni(tem1, tem2);
			cnt++;
		}
		if (!pending()) {
			cout << "Round trip does not exist." << endl;
			continue;
		}
		v[edge[1].u].pop();
		v[edge[1].v].pop();
		int pos = v[edge[1].u].top() < v[edge[1].v].top() ? edge[1].u : edge[2].v;
		dfs(pos);
	}
    return 0;
}

