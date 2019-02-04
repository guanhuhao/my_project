// 2019-1-16 Arbitrage.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
int n;
struct P {
	int num;
	double v;
};
map<string, int> tra;
vector<P> v[35];
int flag;
int vis[35];
int val[35];
void dfs(int now,double value) {
	if (flag == 1)return;
	if (vis[now]) {
		if (value>val[now]) flag = 1;
		return;
	}
	vis[now] = 1;
	val[now]=value;
	for (int i = 0; i < v[now].size(); i++) {
		dfs(v[now][i].num, value*v[now][i].v);
	}
}
double ans[35][35];
/*void dijic(int n) {
	memset(vis, 0, sizeof(vis));
	queue<P> que;
	que.push(P{ n,0 });
	while (!que.empty()) {
		P top = que.front();
		que.pop();
		if (vis[top.num]) continue;
		vis[top.num] = 1;
		for (int i = 0; i < v[top.num].size(); i++) {
			que.push(P{ v[top.num][i].num,top.v*v[top.num][i].v });
			ans[n][top.num] = max( ans[n][top.num],ans[n][top.num] * top.v*v[top.num][i].v );
		}
	}
}*/
void init() {
	tra.clear();
	for (int i = 0; i < 35; i++) v[i].clear();
	memset(vis, 0, sizeof(vis));
	flag = 0;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T = 1;
	while (cin >> n&&n) {
		init();
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			tra[name] = i;
		}
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string a, b;
			double value;
			cin >> a >> value >> b;
			v[tra[a]].push_back(P{ tra[b],value });
		}
		dfs(0, 10000);
		cout << "Case " << T++ << ": " ;
		if (flag)cout << "Yes" << endl;
		else cout << "No" << endl;
		/*for (int i = 0; i < n; i++)
			for (int j = 0; j < v[i].size(); i++)
				cout <<i<<" "<< v[i][j].num << " " << v[i][j].v << endl;*/
	}
    return 0;
}

