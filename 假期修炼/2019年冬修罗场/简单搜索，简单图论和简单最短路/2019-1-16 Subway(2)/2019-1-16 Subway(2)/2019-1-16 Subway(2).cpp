// 2019-1-16 Subway(2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct P {
	int num;
	double x, y;
}p[205];
struct Edge {
	int v;
	double len;
};
vector<Edge> v[205];
double cal(P a,P b){

	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
void connect(P a, P b,int factor) {
	Edge tem;
	tem.v = b.num;
	tem.len = cal(a, b) / factor / 1000 * 60;
	v[a.num].push_back(tem);
	tem.v = a.num;
	v[b.num].push_back(tem);
}
int vis[205];
double ans[205];
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.len > b.len;
	}
};
priority_queue<Edge, vector<Edge>, cmp> que;
void dijic() {
	for (int i = 0; i < 205; i++) ans[i] = 1e9 + 7;
	ans[0] = 0;
	Edge tem;
	tem.len = tem.v = 0;
	que.push(tem);
	while (!que.empty()) {
		Edge top = que.top();
		que.pop();
		if (vis[top.v]) continue;
		vis[top.v] = 1;
		//cout << "text:" << top.len << endl;
		for (int i = 0; i < v[top.v].size(); i++) {
			tem.v = v[top.v][i].v;
			tem.len = v[top.v][i].len + top.len;
			que.push(tem);
			ans[v[top.v][i].v] = min(ans[v[top.v][i].v], v[top.v][i].len + top.len);
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y) {
		for (int i = 0; i < 205; i++) p[i].num = i;
		int cnt = 2;
		while (cin >> p[cnt].x >> p[cnt].y) {
			while (cin >> p[cnt + 1].x >> p[cnt + 1].y&&p[cnt+1].x != -1 && p[cnt+1].y != -1) {
				connect(p[cnt], p[cnt + 1], 40);
				cnt++;
			}
			cnt++;
		}
		for (int i = 0; i < cnt; i++)
			for (int j = i + 1; j < cnt; j++)
				connect(p[i], p[j],10);
		dijic();
		printf("%d\n", (int)(ans[1] + 0.5));
		/*for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < v[i].size(); j++)
				cout << i << " " << v[i][j].v << " " << v[i][j].len << endl;
		}*/
		/*for (int i = 0; i < cnt; i++) {
			cout << i << " " << p[i].x << " " << p[i].y << endl;
		}*/
			
	}
    return 0;
}

