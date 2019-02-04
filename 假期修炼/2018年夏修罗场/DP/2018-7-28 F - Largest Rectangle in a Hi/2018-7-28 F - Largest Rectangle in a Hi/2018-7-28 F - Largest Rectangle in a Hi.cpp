// 2018-7-28 F - Largest Rectangle in a Hi.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn = 1e5 + 50;
ll l[maxn], r[maxn], h[maxn];
stack<ll> sta;
int main()
{
	int n;
	while (cin >> n&&n) {
		
		for (int i = 0; i < n; i++) {
			cin >> h[i];
			if (sta.empty() || h[sta.top()] <= h[i]) {
				l[i] = i;
				sta.push(i);
				
			}
			else {
				while (!sta.empty() && h[sta.top()] > h[i]) {
					r[sta.top()] = i;
					sta.pop();
					
				}
				if (sta.empty()) l[i] = i;
				else l[i] = sta.top();
				sta.push(i);
			}	
		}
		while (!sta.empty()) {
			r[sta.top()] = n;
			sta.pop();
		}
		ll ans = -1;
		for (int i = 0; i < n; i++) cout << l[i] << " " << r[i] << " " << h[i] << endl;
		for (int i = 0; i < n; i++) ans=max(ans, (r[i] - l[i])*h[i] );
		cout << ans << endl;
	}
    return 0;
}

