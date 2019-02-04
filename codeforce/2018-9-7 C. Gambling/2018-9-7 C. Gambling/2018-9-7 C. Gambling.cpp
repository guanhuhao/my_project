// 2018-9-7 C. Gambling.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
ll a[maxn];
ll b[maxn];
bool cmp(ll a, ll b) {
	return a > b;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i]; 
	sort(a, a + n,cmp);
	sort(b, b + n,cmp);
	ll x=0, y=0;
	long long sumx=0, sumy=0;
	for (int i = 0; i < n; i++) {
		if (a[x] > b[y]&&x<n) {
			sumx += a[x];
			x++;
		}
		else y++;
		if (b[y] > a[x]&&y<n) {
			sumy += b[y];
			y++;
		}
		else x++;
	}
	cout << sumx - sumy << endl;
	return 0;
}

