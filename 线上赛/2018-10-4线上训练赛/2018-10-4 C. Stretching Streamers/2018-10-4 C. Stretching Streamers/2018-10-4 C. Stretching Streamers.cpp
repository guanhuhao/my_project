// 2018-10-4 C. Stretching Streamers.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;
bool cmp(int a, int b) {
	return a < b;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
vector<int> v[305];
int vis[305];
long long dfs(int a) {
	ll ans=0;
	for (int i = 0; i < v[a].size(); i++) {
		if (vis[v[a][i]] == 1) continue;
		vis[v[a][i]] = 1;
		ans = (ans+dfs(v[a][i]))%mod;
		vis[v[a][i]] = 0;
	}
	if (ans == 0) return 1;
	return ans;
}
int main()
{
	int n;
	int p[305];
	while (cin >> n) {
		ll ans = 0;
		for (int i = 0; i < 305; i++)v[i].clear();
		memset(p, 0, sizeof(p));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		sort(p,p+n,cmp);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (gcd(p[j] , p[i]) == 1) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
		}
		vis[0] = 1;
		ans=dfs(0);
		cout << ans << endl;
	}
    return 0;
}

