// 2018-8-19 B. Weakened Common Divisor.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long  ll;
ll gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
ll rec[150000 + 10];
pair<ll, ll> a[150000 + 10];
ll su[50000];
int main()
{
	ios::sync_with_stdio(false);
	memset(su, 0, sizeof(su));
	ll n;
	for (int i = 2; i < 300; i++) {
		if (su[i] == 1) continue;
		for (int j = 2; j*i < 50000; j++)
			su[i * j] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 2; i < 50000; i++) {
		if (i == 49999) cout << -1 << endl;
		if (su[i] == 1) continue;
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (a[j].first%i != 0 && a[j].second%i != 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << i << endl;
			break;
		}
	}
    return 0;
}

