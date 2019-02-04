// 2018-9-2 C - John's trip.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Edge {
	int NO;
	int num;
	int used;
	int to;
	int u, v;
}edge[20000];

int fat[500];
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.num >b.num;
	}
};
priority_queue<Edge,vector<Edge>,cmp> que[500];
void init() {
	for (int i = 0; i < 500; i++) {
		fat[i] = i;
		while (!que[i].empty()) que[i].pop();
	}
}


int findf(int a) {
	return fat[a] == a ? a : fat[a] = findf(fat[a]);
}
void uni(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	fat[x] = fat[y];
}
int main()
{
	ios::sync_with_stdio(false);
	int tem1, tem2, tem3;
	while (cin >> tem1 >> tem2) {

		init();		//cout << "1" << endl;
		int k = 0;
		if (tem1==0 && tem2==0) break;
		cin >> tem3;
		que[tem1].push(Edge{ k,tem3,0,tem2 });
		que[tem2].push(Edge{ k,tem3,0,tem1 });		
		edge[k] = { k,tem3,0,0,tem1,tem2 };
		k++;
		while (cin >> tem1 >> tem2) {
			if (tem1==0 && tem2==0) break;
			cin >> tem3;
			que[tem1].push(Edge{ k,tem3,0,tem2 });
			que[tem2].push(Edge{ k,tem3,0,tem1 });
			edge[k] = { k,tem3,0,0 };
			k++;
			uni(tem1, tem2);
		}
		int flag = 0,cnt=0;
		for (int i = 0; i < 50; i++)
			if (que[i].size() % 2 != 0)flag = 1;
		for (int i = 0; i < 50; i++) {
			if (!que[i].empty() && fat[i] == i) cnt++;
		}
		if (flag ||cnt>1) {
			cout << "Round trip does not exist." << endl;
			continue;
		}
		int pos;
		for (int i = 0; i < k; i++) {
			if (edge[i].num == 1) {
				que[edge[i].u].pop();
				que[edge[i].v].pop();
				pos = que[edge[i].u].top().num < que[edge[i].v].top().num ? edge[i].u : edge[i].v;
				cout << "1";
				break;
			}
		}
		while (!que[pos].empty()) {
			Edge tem = que[pos].top();
			que[pos].pop();
			if (edge[tem.NO].used) continue;
			edge[tem.NO].used = 1;
			pos = tem.to;
			cout <<" "<< tem.num ;
		}
		cout << endl;
	}
    return 0;
}

