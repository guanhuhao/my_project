// 2018-7-25 D.message.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 1010;
long long a[maxn][maxn] = {0};
long long jic[maxn];
long long qs(long long a, long long b) {
	long long base = a;
	long long ans = 1;
	while (b != 0) {
		if (b % 2 == 1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		b /= 2;
	}
	return ans%mod;
}
void init() {
	jic[1] = 1;
	for (int i = 2; i < maxn; i++) jic[i] = (jic[i] * jic[i - 1]) % mod;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j <= i; j++)
		{
			a[i][j] = (jic[i] * qs(jic[j], mod - 2)) % mod;
			a[i][j] = (a[i][j] * qs(jic[i - j], mod - 2)) % mod;
		}
	}
}
priority_queue<int> que;

int main()
{
	que.
	int n, m;
	while (cin >> n >> m) {
		cout<<a[n+m-3][n-1]*a[n+m-3][m-1]-a[n+m-4][]
	}
	
	
    return 0;
}

