// 2018-12-1 Janitor Troubles.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const long double esp = 1e-7;
bool cmp(long double a, long double b) {
	return a > b;
}
long double _abs(long double a) {
	return a > 0 ? a : -a;
}
int main()
{
	long double edge[4];
	long double ans = 0;
	cin >> edge[0] >> edge[1] >> edge[2] >> edge[3];
	long double sum = edge[0] + edge[1] + edge[2] + edge[3];
	sort(edge, edge + 4, cmp);
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			long double c1 = edge[i], c2 = edge[j];
			long double a, b, c;
			for (int k = 0; k < 4; k++) if (k != i&&k != j) a = edge[k];
			b = sum - a - c1 - c2;
			c = c1 - c2;
			if (2 * max(max(a, b), c) > a + b + c + esp) continue;
			long double p = (a + b + c) / 2;
			if (_abs(c) < esp) ans = max(ans, a*c1);
			else {
				ans = max(ans, (c1 + c2)*sqrt(p*(p - a)*(p - b)*(p - c)));
			}
			//cout << "text:" << a << " " <<b<<" "<<c<<" "<<h<< endl;
		}
	}
	printf("%.15Lf\n", ans);
	return 0;
}

