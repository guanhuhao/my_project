// 2018-9-8 Largest Rectangle in a.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
ll l[maxn];
ll r[maxn];
ll num[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n&&n) {
		for (int i = 0; i < n; i++) cin >> num[i];
		l[0] = 0;
		r[n - 1] = n-1;
		for (int i = 1; i < n; i++) {
			int tem = i - 1;
			while (num[i] >= num[tem] && tem >= 0) {
				tem = l[tem] - 1;
			}
			l[i] = tem + 1;
		}
		for (int i = n - 2; i >= 0; i--) {
			int tem = i + 1;
			while (num[i] <= num[tem]&&tem<n) {			
				tem = r[tem] + 1;		
			}
			r[i] = tem - 1;
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			cout << "text:" << l[i] << " " << r[i]+1 << " " << num[i] << endl;
			ans = max(ans, (r[i] - l[i]+1)*num[i]);
		}
		cout << ans << endl;
	}
    return 0;
}

