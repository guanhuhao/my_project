// 2018-8-21 E - Quantum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
const int const *(*a)();
using namespace std;
int t;		
int l, nop, nw;
int ans;
int cost[2100000];
int sta[25], tar[25];
struct ope {
	string com;
	long long v;
}op[35];			

int has(int a[]) {
	int h = 0;
	for (int i = 0; i < l; i++) {
		h = (h << 1) + a[i];
	}			
	//cout << "text:"<<h << endl;
	return h;
}
struct node {
	int a[25];
	int v;
};
struct cmp {
	bool operator()(node a, node b) {
		return a.v > b.v;
	}
};
priority_queue<node, vector<node>, cmp> que;
long long bfs() {
	while (!que.empty()) que.pop();
	memset(cost, -1, sizeof(cost));
	node tem2;
	for (int i = 0; i < l; i++)  tem2.a[i] = sta[i]; 
	tem2.v = 0;
	cost[has(tem2.a)] = 0;
	que.push(tem2);
	while (!que.empty()) {
		node tem = que.top();
		que.pop();
		int ha1 = has(tem.a);
		if (ha1 == ans) return cost[ha1];
		for (int i = 0; i < nop; i++) {
			node other;
			for (int j = 0; j < l; j++) {
				if (op[i].com[j] == 'N')	  other.a[j] = tem.a[j];
				else if (op[i].com[j] == 'F') other.a[j] = 1^tem.a[j];			
				else if (op[i].com[j] == 'S') other.a[j]= 1;
				else if (op[i].com[j] == 'C') other.a[j] = 0;
			}					
			int h = has(other.a);

			other.v = tem.v + op[i].v;
			if (cost[h] == -1 || other.v < cost[h]) {
				cost[h] = other.v;
				que.push(other);
			}
		}
	}
	return -1;
}
int main()
{
	
	cin >> t;
	while (t--) {
		cin >> l >> nop >> nw;
		for (int i = 0; i < nop; i++) cin >> op[i].com >> op[i].v;
		for (int i = 0; i < nw; i++) {

			for (int j = 0; j < l; j++) scanf("%1d", &sta[j]);
			for (int j = 0; j < l; j++) scanf("%1d", &tar[j]);
			ans = has(tar);
			int flag = bfs();
			if (flag == -1) cout << "NP ";
			else cout << flag << " ";
		}
		cout << endl;
	}
    return 0;
}

