// 2018-8-20 E - Quantum（2）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct Str{
	string str;
	int cost;
	int same;
};
struct Com {
	string com;
	int cost;
}com[35];
struct cmp {
	bool operator()(Str a, Str b) {
		return a.cost > b.cost;
	}
};
priority_queue<Str, vector<Str>, cmp> que;
int check(Str a,string tar) {
	int i;
	for (i = 0; (i < tar.size()) && a.str[i] == tar[i]; i++);
	return i;
}
void oper(string &a, string tar) {

}
int bfs(string sta, string tar) {
	while (!que.empty()) {
		Str tem = que.top();
		que.pop();
		tem.same = check(tem, tar);
		
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int l, nop, nw;
		cin >> l >> nop >> nw;
		for (int i = 0 ; i < nop; i++) {
			cin >> com[i].com >> com[i].cost;
		}
		for (int i = 0; i < nw; i++) {
			string start, tar;
			cin >> start >> tar;
		}
	}
    return 0;
}

