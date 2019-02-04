// 2018-8-1 B - Radar Installation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<long long, long long> P;
struct cmp{  
	bool operator () (P a, P b) {
		return a.first > b.first || (a.first == b.first&&a.second > b.second);
	}
};
priority_queue<P, vector<P>, cmp> que;

int main()
{
	long long n, r, k=0;
	ios::sync_with_stdio(false);
	while (cin >> n >> r) {
		k++;
		if (n == 0 && r == 0) break;
		int flag = 0;
		for (int i = 0; i < n; i++) {
			long long tem1, tem2;
			cin >> tem1 >> tem2;
			if (tem2 > r) {
				flag = 1;
				continue;
			}
			que.push(P(tem1 - sqrt(r*r - tem2*tem2), tem1 + sqrt(r*r - tem2*tem2)));
		}
		if (flag == 1) {
			cout << "Case " << k << ": " << -1 << endl;
			continue;
		}
		int ans = 0;
		//cout << endl << endl;
		while (!que.empty()) {
			int r = (que.top()).second;
			while (!que.empty()&&que.top().first <= r) {
				int tem = que.top().second;
				r = min(tem, r);
				//cout << que.top().first << "  " << que.top().second << endl;
				que.pop();
				//cout << r << endl;
			}
			ans++;
		}
		cout << "Case " << k << ": " << ans << endl;
	}
    return 0;
}

