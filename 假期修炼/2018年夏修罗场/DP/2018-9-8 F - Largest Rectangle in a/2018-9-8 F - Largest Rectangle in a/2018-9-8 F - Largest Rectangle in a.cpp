// 2018-9-8 F - Largest Rectangle in a.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct col {
	ll l,r, h;
};
stack<col> sta;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n&&n) {
		ll ans = 0;
		sta.push(col{ 0,0,-1 });
		for (int i = 0; i < n; i++) {
			ll hei;
			cin >> hei;
			if (hei > sta.top().h) sta.push(col{ i,i+1,hei });
			else {
				while (sta.top().h >= hei) {
					ans = max(ans, sta.top().h*(i - sta.top().l));
					sta.pop();
				}
				sta.push(col{ sta.top().r,i+1, hei });
			}
		}
		while (!sta.empty()) {
			ans = max(ans, sta.top().h*(n - sta.top().l));
			sta.pop();
		}
		cout << ans << endl;
	}
    return 0;
}

