// 2018-8-11 C. Elections.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
P tem[3030];
int jishu[3030];
vector<P> v;
vector<P> maxi;
bool cmp(P a, P b) {
	return a.second < b.second;
}
int main()
{
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(jishu, 0, sizeof(jishu));
	for (int i = 0; i < n; i++) {
		ll tem1, tem2;
		cin >> tem[i].first >> tem[i].second;
		jishu[tem1]++;
	}
	int rec = 1;
	for (int i = 2; i <= n; i++) {
		if (jishu[i] > jishu[rec]) {
			rec = i;
		}
	}
	if (rec == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (tem[i].first == 1) continue;
		if (tem[i].first == rec) maxi.push_back(tem[i]);
		else v.push_back(tem[i]);
	}
	sort(v.begin(), v.end(), cmp);
	sort(maxi.begin(), maxi.end(), cmp);
	for (int i = 1; i < v.size(); i++) v[i].second += v[i - 1].second;
	for (int i = 1; i < maxi.size(); i++) maxi[i].second += maxi[i-1].second;
	ll mini = 1e18;
	for(int i=0;jishu[1]+2*)
    return 0;
}

