// 2018-8-31 F - The Robbery (2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[20];
ll t,m,n;
ll ans;
struct thing {
	ll w, v, n;
}a[20];
void init() {
	for (int i = 0; i < 20; i++) a[i].w = a[i].v = a[i].n = 0;
	memset(sum, 0, sizeof(sum));
	ans = 0;
}
bool cmp(thing a, thing b) {
	return (double)a.v / a.w > (double)b.v / b.w;
}
void dfs(ll deep,ll cost, ll wei) {
	ans = max(ans, cost);
	if (deep > n) return;
	if (cost + sum[n] - sum[deep - 1] < ans) return;
	if ((double)a[deep].v / a[deep].w*wei +cost < ans)return;
	for (int i = a[deep].n; i >= 0; i--) {
		if ( i*a[deep].w > wei) continue;
		dfs(deep + 1, cost + i*a[deep].v, wei - i*a[deep].w);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		init();
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i].w;
		for (int i = 1; i <= n; i++) cin >> a[i].v;
		for (int i = 1; i <= n; i++) a[i].n = i;
		sort(a + 1, a + n+1,cmp);
		for (int i = 1; i <= n; i++) sum[i] += sum[i - 1] + a[i].n*a[i].v;
		dfs(1, 0, m);
		cout << ans << endl;
	}
    return 0;
}

