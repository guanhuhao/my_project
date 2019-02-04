// 2018-9-17 D. Petya and Array(2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct T{
	ll l, r, v;
}tree[maxn*4];
void built(ll l, ll r, ll k) {
	int mid = (l + r) / 2;
	tree[k].l = l;
	tree[k].r = r;
	if (l == r) {
		cin >> tree[k].v;
		return;
	}
	built(l, mid, 2 * k);
	built(mid + 1, r, 2 * k + 1);
	tree[k].v = tree[2 * k + 1].v + tree[2 * k].v;
}
int main()
{
	ios::sync_with_stdio(false);
	ll n, k;
	for (int i = 0; i < maxn * 4; i++) tree[i].v = 1e18;
	cin >> n >> k;
	built(1, n, 1);
	int ans = 0;
	for (int i = 1; i < 4 * maxn; i++) {
		if(tree[i].v!=1e18)			cout << "text:" << tree[i].l << " " << tree[i].r << " " << tree[i].v << endl;
		if (tree[i].v <= k) {
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}

