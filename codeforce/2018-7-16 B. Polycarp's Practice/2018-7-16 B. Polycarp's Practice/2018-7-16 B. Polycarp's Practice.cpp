// 2018-7-16 B. Polycarp's Practice.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct node {
	int n, v;
}a[2020];
bool cmp1(node a, node b) {
	return a.v > b.v;
}
bool cmp2(node a, node b) {
	return a.n < b.n;
}
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		a[i].n = i;
	}
	int ans = 0;
	sort(a, a + n, cmp1);
	for (int i = 0; i < k; i++) ans += a[i].v;
	sort(a, a + k, cmp2);
	cout << ans << endl;
	a[0].n = 0;
	for (int i = 1; i < k; i++) {
		cout << a[i].n - a[i - 1].n << " ";
	}
	cout << n - a[k-1].n << endl;
    return 0;
}

