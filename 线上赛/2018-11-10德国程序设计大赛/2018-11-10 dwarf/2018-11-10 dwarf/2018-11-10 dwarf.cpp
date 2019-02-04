// 2018-11-10 dwarf.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
map<string, int> check;
vector<int> v[10010];
int du[10010];
int main()
{
	memset(du, 0, sizeof(du));
	int n;
	int k = 0;
	int flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name1, name2, sym;
		cin >> name1 >> sym >> name2;
		if (flag == 1)continue;
		if (sym == "<") swap(name1, name2);
		if (check[name1] == 0) check[name1] = ++k;
		if (check[name2] == 0) check[name2] = ++k;
		v[check[name1]].push_back(check[name2]);
		du[check[name2]]++;
	}
	queue<int> que;
	for (int i = 1; i <= 10005; i++) if (du[i] == 0) que.push(i);
	while (!que.empty()) {
		int top = que.front();
		que.pop();
		for (int i = 0; i < v[top].size(); i++) {
			du[v[top][i]]--;
			if (du[v[top][i]] == 0) que.push(v[top][i]);
		}
	}
	for (int i = 0; i <= 10005; i++) if (du[i] != 0) flag = 1;
	cout <<( flag == 1 ? "impossible" : "possible" )<< endl;
    return 0;
}

