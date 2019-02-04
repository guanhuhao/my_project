// 2019-1-15 Shuffle'm Up.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
string a, b, c;
map<string, int> check;
queue<string> que;
int n;
string add(string a, string b) {
	string ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(a[i]);
		ans.push_back(b[i]);
	}
	return ans;
}
void bfs() {
	que.push(a + b);
	while (!que.empty()) {
		string a, b,top=que.front();
		que.pop();
		for (int i = 0; i < n; i++) {
			a.push_back(top[i]);
			b.push_back(top[n + i]);
		}
		string tem=add(b,a);
		if (!check[tem]) {
			que.push(tem);
			check[tem] = check[top] + 1;
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T;i++) {
		check.clear();
		cin >> n;
		cin >> a >> b >> c;
		bfs();
		cout << i << " ";
		if (check[c] == 0) cout << -1 << endl;
		else cout << check[c] << endl;
		//for (auto i = check.begin(); i != check.end(); i++) cout << i->first << " " << i->second << endl;
	}
		return 0;
}

