#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n,cmp);
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (a[i - 1] - a[i] > m)ans++;
	}
	cout << ans << endl;
}