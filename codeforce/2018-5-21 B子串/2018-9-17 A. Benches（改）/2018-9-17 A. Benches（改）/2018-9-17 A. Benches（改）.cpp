// 2018-9-17 A. Benches（改）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a[110];
	int maxi = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)maxi = max(maxi, a[i]);
	int ans2 = m;
	for (int i = 0; i < n; i++) {
		m -= maxi - a[i];
	}
	if (m <= 0) cout << maxi << " ";
	else {
		if (m%n == 0) cout << maxi + m / n << " ";
		else cout << maxi + m / n + 1 << " ";
	}
	cout << ans2 +maxi<< endl;
    return 0;
}

