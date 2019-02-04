// 2019-1-19 Supermarket.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
using namespace std;
struct P {
	int v, t;
	P() {};
};
struct cmp1 {
	bool operator()(P a, P b) {
		return a.v < b.v;
	}
};
priority_queue< P,vector<P>,cmp1 > que;

P date[100010];
bool cmp(P a, P b) {
	return a.t > b.t || (a.t == b.t&&a.v > b.v);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n) {
		while (!que.empty()) que.pop();
		for (int i = 0; i < n; i++) {
			cin >> date[i].v >> date[i].t;
		}
		sort(date, date+n,cmp);
		int tt=date[0].t;
		int ans = 0;
		int cnt = 0;

		while (tt != 0 ) {	
			if (que.empty()&&cnt!=n) {
				que.push(P{ date[cnt] });
				tt = date[cnt].t;
				cnt++;
			}
			P top = que.top();
			que.pop();
			ans += top.v;
			//cout << "text:" << top.v << " " << tt << endl;
			//cout << "text2:" << " ";
			tt--;
			for (; cnt < n; cnt++) {
				if (date[cnt].t >= tt) {
					que.push(P{ date[cnt] });
				//	cout << date[cnt].v << " ";
					continue;
				}
				break;
			}
			//cout << endl;
		}
		cout << ans << endl;
	}
    return 0;
}

