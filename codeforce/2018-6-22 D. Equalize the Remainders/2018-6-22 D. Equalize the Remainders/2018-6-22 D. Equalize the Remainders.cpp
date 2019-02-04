// 2018-6-22 D. Equalize the Remainders.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
long long num[maxn];
long long a[maxn];
long long b[maxn] = { 0 };
int main()
{
	int n, m;
	int ans = 0;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int k = n / m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		a[i] = num[i] % m;
		b[a[i]]++;
	}

	for (int i = 0; i < n; i++) {
		if (b[a[i]] > k) {
			for (int j = 1; j < m; j++) {
				if ((b[(a[i] + j) % m] < k)) {
					ans += j;
					num[i] += j;
					b[(a[i] + j) % m]++;
					b[a[i]]--;
					a[i] = (a[i] + j) % m;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) cout << num[i] << " ";
	cout << endl;
    return 0;
}

