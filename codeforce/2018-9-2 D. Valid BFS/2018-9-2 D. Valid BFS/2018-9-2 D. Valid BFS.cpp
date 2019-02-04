// 2018-9-2 D. Valid BFS.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int deep[maxn];
int mark[maxn];
int text[maxn];
vector<int> v[maxn];

void solve(int root) {
	queue<int> que;
	que.push(root);
	mark[root] = 1;
	while (!que.empty()) {
		int top = que.front();
		que.pop();
		int size = v[top].size();
		for (int i = 0; i < size; i++) {
			int tem = v[top][i];
			if (mark[tem] == 0) {
				mark[tem] = 1;
				que.push(tem);
				deep[tem] = deep[top] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	memset(mark, 0, sizeof(mark));
	memset(deep, 0, sizeof(deep));
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		v[tem1].push_back(tem2);
		v[tem2].push_back(tem1);
	}
	for (int i = 0; i < n; i++) cin >> text[i];
	int root = text[0];
	solve(root);
	int flag = 0;
	for (int i = 0; i < n-1; i++) {
		if (deep[text[i]] > deep[text[i + 1]]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		root = text[n - 1];
		memset(mark, 0, sizeof(mark));
		memset(deep, 0, sizeof(deep));
		solve(root);
		int flag2 = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (deep[text[i]] > deep[text[i - 1]]) {
				flag2 = 1;
			}
		}	//for (int i = 1; i <= n; i++) cout << "text:" << deep[i] << endl;
		if(flag2==1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	else cout << "Yes" << endl;
    return 0;
}

