// 2018-9-17 A. Benches.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[1010];
	int sum = 0, maxi = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		sum += a[i];
		maxi = max(maxi, a[i]);
	}
	int ans1,ans2;
	sum += m;
	if (sum%n == 0) ans1 = sum / n;
	else ans1 = sum / n + 1;
	ans2 = maxi + m;
	cout << ans1 << " " << ans2<<endl;
    return 0;
}

