// 2018-8-31 F - The Robbery.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
ll n, m, t;
ll w[20], v[20];
ll sum[1000];
struct thing {
	ll w, v;
};


vector<thing> vec;
ll ans;
void init() {
	memset(w, 0, sizeof(w));
	memset(v, 0, sizeof(v));
	memset(sum, 0, sizeof(sum));
	vec.clear();
	ans = 0;
}
void dfs(ll deep, ll cost, ll wei) {
	ans = max(cost, ans);
	if (deep == vec.size()) return;
	if ((double)vec[deep].v / vec[deep].w*wei + cost < ans) return;
	if (cost + sum[vec.size()] - sum[deep] < ans) return;
	dfs(deep + 1, cost, wei);
	if (vec[deep].w > wei)return;	
	dfs(deep + 1, cost + vec[deep].v, wei - vec[deep].w);

}

bool cmp(thing a, thing b) {
	return (double)a.v / a.w > (double)b.v / b.w;
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> w[i];
		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 1; i <= n; i++) {
			int tem = i;
			for (int j = 1; j <= tem; (j <<= 1)) {
				ll ww = w[i] * j;
				ll vv = v[i] * j;
				vec.push_back(thing{ ww,vv });
				tem -= j;
			}
			if (tem != 0) vec.push_back(thing{ w[i] * tem,v[i] * tem });
		}
		sort(vec.begin(), vec.end(), cmp);
		for (int i = 1; i <= vec.size(); i++) sum[i] = sum[i - 1] + vec[i - 1].v;
		//for (int i = 0; i <= vec.size(); i++) cout << "text:" << sum[i] << endl;
		//for (int i = 0; i < vec.size(); i++) cout << "text:" << vec[i].v << " " << vec[i].w << endl;
		dfs(0, 0, m);
		cout << ans << endl;
	}
	return 0;
}

