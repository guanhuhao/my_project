// 2018-10-2 F. Mountain Scenes.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll ans = 0;
int rec[10005][105];
ll dfs(ll remain, ll w, ll h) {
	ll ans = 0;
	if (w == 0) return 1;
	if (rec[remain][w]) return rec[remain][w];
	for (int i = 0; i <= h; i++) {
		if (i > remain) break;
		ans+=dfs(remain - i, w - 1, h);
		ans %= mod;
	}
	return rec[remain][w]=ans%mod;
}

int main()
{
	ll n, w, h;
	while (cin >> n >> w >> h) {
		memset(rec,0,sizeof(rec));
		/*for (int i = w; i >= 0; i--) {
			for (int j = n; j >= 0; j--) {

					rec[n - k][w - 1] = rec[n][w];
				}
			}
		}*/
		int cnt = min(h+1, n / w+1);
		cout<<dfs(n, w, h)-cnt<<endl;
	}
    return 0;
}

