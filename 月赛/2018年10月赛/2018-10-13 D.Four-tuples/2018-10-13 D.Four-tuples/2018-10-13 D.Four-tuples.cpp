// 2018-10-13 D.Four-tuples.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct Edge {
	ll l, r, v;
}edge[4];
ll fun1(Edge a, Edge b) {
	ll maxi = max(a.l, b.l);
	ll mini = min(a.r, b.r);
	return max((ll)0, mini-maxi+1);
}
ll fun2(Edge a, Edge b,Edge c) {
	ll maxi = (a.l, b.l);
	maxi = max(maxi, c.l);
	ll mini = (a.r, b.r);
	mini = min(mini, c.r);
	return  max((ll)0, mini-maxi+1);
}
ll fun3(Edge a, Edge b, Edge c,Edge d) {
	ll maxi = (a.l, b.l);
	maxi = max(maxi, c.l);
	maxi = max(maxi, d.l);
	ll mini = (a.r, b.r);
	mini = min(mini, c.r);
	mini = min(mini, d.r);
	return  max((ll)0, mini-maxi+1);
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++) cin >> edge[i].l >> edge[i].r;
		for (int i = 0; i < 4; i++) edge[i].v = edge[i].r - edge[i].l + 1;
		ll ans = 1;
		for (int i = 0; i < 4; i++) ans = (ans*edge[i].v)%mod;	
		
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				ll mul = 1;
				for (int k = 0; k < 4; k++) {
					if (k == i || k == j) continue;
					mul = (mul*edge[k].v)%mod;
				}
				if ((i == 1 && j == 3) || (i == 0 && j == 2)) continue;
				ans = (ans-(fun1(edge[i], edge[j])*mul)%mod+mod)% mod;
			}
		}
		ans = (ans + fun2(edge[0], edge[1], edge[2])*edge[3].v) % mod;
		ans = (ans + fun2(edge[0], edge[1], edge[3])*edge[2].v) % mod;
		ans = (ans + fun2(edge[0], edge[2], edge[3])*edge[1].v) % mod;
		ans = (ans + fun2(edge[2], edge[1], edge[3])*edge[0].v) % mod;

		ans = (ans - fun3(edge[0], edge[1], edge[2], edge[3])+mod)%mod;

		ans = (ans - fun1(edge[0], edge[2])*fun1(edge[1], edge[3]) % mod + mod) % mod;
		cout << ans << endl;
	
	}
    return 0;
}

