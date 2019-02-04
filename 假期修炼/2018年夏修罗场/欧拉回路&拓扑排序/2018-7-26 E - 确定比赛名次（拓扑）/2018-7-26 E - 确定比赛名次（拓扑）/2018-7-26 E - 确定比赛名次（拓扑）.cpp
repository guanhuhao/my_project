// 2018-7-26 E - 确定比赛名次（拓扑）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> a[505];
int check[505][505];
int du[505];
const int inf = (int)1e9;
queue<int> que;
void init() {
	memset(du, 0, sizeof(du));
	memset(check, 0, sizeof(check));
	for (int i = 0; i < 505; i++) a[i].clear();
	while (!que.empty()) que.pop();
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			if (check[tem1][tem2] == 0) {
				a[tem1].push_back(tem2);
				du[tem2]++;
				check[tem1][tem2] = 1;
			}
		}
		while (que.size() != n) {
			int tem;
			for (int i = 1; i <= n; i++) {
				if (du[i] == 0) {
					que.push(i);
					du[i] = inf;
					tem = i;
					break;
				}
			}
			while (!a[tem].empty()) {
				du[a[tem].back()]--;
				a[tem].pop_back();
			}
		}
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

