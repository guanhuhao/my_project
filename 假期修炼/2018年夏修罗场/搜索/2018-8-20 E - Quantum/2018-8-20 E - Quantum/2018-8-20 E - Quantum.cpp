// 2018-8-20 E - Quantum.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> P;
int l, nop, nw;
struct cmp {
	bool operator()(P a, P b) {
		return a.second > b.second;
	}
};		
priority_queue<P,vector<P>,cmp> que;
P com[35];
string op(int i, string a) {
	string tem = com[i].first;
	string ans ;
	for (int i = 1; i <= a.size; i++) ans[i - 1] = a[i];
	for (int i = 0; i < tem.size(); i++) {
		if (tem[i] == 'N') continue;
		if (tem[i] == 'F') a[i] = a[i] ^ 1;
		if (tem[i] == 'S') a[i] = a[i] | 1;
		if (tem[i] == 'C')a[i] = a[i] & 0;
	}
	return ans;
}
int bfs(string start, string end) {
	while (!que.empty()) {
		P top = que.top();
		que.pop();
		for (int i = 0; i < nop; i++) {
			string str = op(i, top.first);
			int v = top.second + com[i].second;
			if()
		}
	}
	return 0;
}
int main()
{
	int t;
	//cout << -10 % (-3) << endl;
	cin >> t;
 
	while (t--) {

		while (!que.empty()) que.pop();
		cin >> l >> nop >> nw;
		for (int i = 0; i < nop; i++) {
			cin >> com[i].first >> com[i].second;
			for (int i = 0; i < com[i].first.size(); i++) com[i].first[i] -= '0';
		}

		for (int i = 0; i < nw; i++) {
			string start, targe;
			cin >> start >> targe;
			for (int i = 0; i < start.size(); i++) {
				start[i] -= '0';
				targe[i] -= '0';
			}
		}
	}
    return 0;
}

