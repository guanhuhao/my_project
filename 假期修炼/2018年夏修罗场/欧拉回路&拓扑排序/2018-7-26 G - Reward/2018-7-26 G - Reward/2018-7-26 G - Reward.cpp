// 2018-7-26 G - Reward.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> a[10010];
typedef pair<int, int> P;
int du[10010];
void init() {
	for (int i = 0; i < 10010; i++) a[i].clear();
	memset(du, 0, sizeof(du));
}

int main()
{
	int n, m;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			a[tem2].push_back(tem1);
			du[tem1]++;
		}
		int money = 888;
		int ans = 0;
		int tem=1;
		int sum = 0;
		while (tem) {
			tem=0;
			queue<int> que;
			for (int i = 1; i <= n; i++) {
				if (du[i] == 0) {
					tem++;
					while (!a[i].empty()) {
						que.push(a[i].back());
						a[i].pop_back();
					}
					du[i] = 10000000;
				}
			}
			ans += tem*money;
			sum += tem;
			money++;
			while (!que.empty()) {
				du[que.front()]--;
				que.pop();
			}
		}
		int sum2 = 0;
		for (int i = 1; i <= n; i++) sum2 += a[i].size();
		if (sum2) cout << -1 << endl;
		else  cout << ans+money*(n-sum) << endl;
	}
    return 0;
}

