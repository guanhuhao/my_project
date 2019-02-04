// 2018-6-27 B. Light It Up.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
const int maxn = (int)2e5 + 10;
struct P {
	int v;
	int b, a;
}p[maxn];
using namespace std;
int main()
{
	int n, m;
	int sum=0;
	int ans;
	cin >> n >> m;
	p[0].v =p[0].v =0;
	for (int i = 1; i <= n; i++) cin >> p[i].v;
	p[n + 1].v = m;
	for (int i = 0; i <= n+1;i++) {
		if (i % 2 == 1) {
			p[i].b = p[i - 2 < 0 ? 0 : i - 2].b + p[i].v - p[i - 1].v;
			sum += p[i].v - p[i - 1].v;
		}
		else p[i].b = p[i - 1].b;
	}
	ans = sum;
	for (int i = 0; i <= n - 1; i++)p[i].a = m - p[i].v-(sum-p[i].b);
	for (int i = 0; i <= n + 1; i++) {
		if (i % 2 == 0 && i != 0 && p[i].v - 1 != p[i - 1].v) {
			ans = max(ans, p[i - 1].b + p[i].v-1-  p[i - 1].v + p[i].a);
		}
		else if (i % 2 == 1 && p[i].v - 1 != p[i - 1].v) {
			ans = max(ans, p[i].b - 1 + p[i].a);
		}
	}
	cout << ans << endl;
	/*for (int i = 0; i <= n + 1; i++) {
		cout << p[i].v << "  " << p[i].b <<"  "<<p[i].a<< endl;
	}*/
    return 0;
}

