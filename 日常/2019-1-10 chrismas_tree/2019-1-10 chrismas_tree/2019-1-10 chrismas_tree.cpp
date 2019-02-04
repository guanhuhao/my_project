// 2019-1-10 chrismas_tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
long double qmul(long double a, int k) {
	long double ans = a;
	if (k == 0) return 1;
	while (k!=1) {
		ans *= ans;
		if (k % 2 == 1) ans *= a;
		k /= 2;
	}
	return ans;
}
int main()
{
	int T;
	long double l, r;
	cin >> T;
	while (T--) {
		long double ans = 0;
		long double tem = 1;
		cin >> l >> r;
		if (l >= 1 - 0.0001&&r >= 1 - 0.0001) {
			cout << "1.000" << endl;
			continue;
		}
		//cout << qmul(l, (int)r) << endl;
		for (int i = 0; i < 5; i++) {
			tem = qmul(l*r,(1<<i)-1)*qmul((1 - l)*(1 - r), 1<<i);
			ans += tem;
		}
		printf("%.3Lf\n", ans);

	}
    return 0;
}

