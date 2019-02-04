// 2018-7-27 C - John's trip.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
queue<int> que;
struct EDGE {
	int u, v;
}edge[2000];
int vis[50];
int fat[50];
int du[50];
int check[2000];
int maxi;
void init() {
	while (!que.empty()) que.pop();
	memset(check, 0, sizeof(check));
	for (int i = 0; i < 2000; i++) edge[i].u = edge[i].v = 0;
	for (int i = 0; i < 50; i++) fat[i] = i;
	memset(vis, 0, sizeof(vis));
	memset(du, 0, sizeof(du));
}
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void unionnode(int a, int b) {
	int x = findf(a), y = findf(b);
	if (x != y) fat[x] = fat[y];
}
void dfs(int x) {
	for (int i = 0; i <= maxi; i++) {
		if (!check[i]&&(edge[i].u == x || edge[i].v == x)) {
			que.push(i);
			check[i] = 1;
			int tem1 = edge[i].u + edge[i].v;
			dfs(tem1 - x);
		}
	}
}
int main()
{
	int x, y, z;
	while (cin >> x >> y&&(x||y)) {
		init();
		cin >> z;
		maxi = z;
		edge[z].u = x;
		edge[z].v = y;
		du[x]++; du[y]++;
		vis[x] = vis[y] = 1;
		unionnode(x, y);
		while (cin >> x >> y&&(x||y)) {
			cin >> z;
			edge[z].u = x;
			maxi = max(maxi, z);
			edge[z].v = y;
			vis[x] = vis[y] = 1;
			du[x]++; du[y]++;
			unionnode(x, y);
		}
		for (int i = 0; i < 50; i++) findf(i);
		int cnt = 0;
		for (int i = 0; i < 50; i++) {
			if (vis[i] == 1 && fat[i] == i)cnt++;
		}

		if (cnt > 1) {
			cout << "Round trip does not exist." << endl;
			continue;
		}
		int flag1 = 0;
		for (int i = 0; i < 50; i++) {
			if (du[i] % 2 != 0) {
				cout << "Round trip does not exist." << endl;
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1) continue;
		dfs(1);
		cout << que.front();
		que.pop();
		while (!que.empty()) {
			cout << " " << que.front();
			que.pop();
		}
		cout << endl;
	}
    return 0;
}

