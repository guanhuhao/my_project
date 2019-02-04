// 2018-10-2 Fancy Antiques.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
map<int, int> check;
struct P {
	int a, b, v;
};
vector<P> v;
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k) {
		check.clear();
		v.clear();
		for (int i = 0; i < n; i++) {
			int a, ap, b, bp;
			cin >> a >> ap >> b >> bp;
			if (ap < bp) check[a] += ap;
			else if (bp < ap)check[b] += bp;
			else v.push_back(P{a, b,ap});
		}
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (check[v[i].a] != 0) check[v[i].a] += v[i].v;
			else if (check[v[i].b != 0]) check[v[i].b] += v[i].v;
			else continue;
			v[i].v = 0;
			cnt++;
		}
		while (cnt < v.size()) {
			int check2[45];
			int maxi = 0;
			memset(check2, 0, sizeof(check2));
			for (int i = 0; i < v.size(); i++) {
				if (v[i].v == 0) continue;
				check2[v[i].a]++;
				check2[v[i].b]++;
			}
			for (int i = 0; i < v.size(); i++) {
				if (check2[maxi] < check2[i])maxi = i;
			}
			for (int i = 0; i < v.size(); i++) {
				if (v[i].a == check2[maxi] || v[i].b == check2[maxi]) {
					check[maxi] += v[i].v;
					cnt++;
					v[i].v = 0;
				}
			}
		}
		if (check.size() > k) cout << -1<<endl;
		else {
			int ans = 0;
			for (auto i = check.begin(); i != check.end(); i++) ans += i->second;
			cout << ans << endl;
		}
	}
    return 0;
}

