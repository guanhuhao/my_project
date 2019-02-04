// 2018-8-5 A - rua.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
double a[10010];
int main()
{
	long long n, k;
	double maxi = -1;
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
		maxi = max(maxi, a[i]);
	}
	double l = 0.00, r = maxi;
	while (r - l > 0.00000001) {
		double mid = (r + l) / 2;
		long long num = 0;
		for (int i = 0; i < n; i++) {
			num += a[i] / mid;
		}
		if (num >= k) {
			l = mid;
		}
		else r = mid;
	}
	if (r < 0.01) printf("0.00\n");
	else printf("%.2lf\n", floor(r*100)/100);
	//cout << floor(l * 100) << endl;
	//printf("%lf\n", floor(r*100));
	return 0;
}

