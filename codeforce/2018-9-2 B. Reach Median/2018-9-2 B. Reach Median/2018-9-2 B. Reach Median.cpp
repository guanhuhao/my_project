// 2018-9-2 B. Reach Median.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
ll a[maxn];
int main()
{
	ll n, mid;
	ll ans = 0;
	cin >> n >> mid;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	//for (int i = 0; i < n; i++)cout << a[i] << " ";
	//cout << endl;
	ll midd = a[n / 2];
	if (midd > mid) {
		for(int i=n/2;i>=0;i--){
			if (a[i] > mid) ans += a[i] - mid;
			else break;
		}
	}
	else if (midd < mid) {
		for (int i = n / 2; i < n; i++) {
			if (a[i] < mid)ans += mid - a[i];
		}
	}
	cout << ans << endl;
    return 0;
}

