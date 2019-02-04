// 2018-8-19 D. Mouse Hunt.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
int f[maxn];
int findf(int a) {
	if (f[a] == a) return a;
	else return f[a] = findf(f[a]);
}
void u(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	if (x != y) f[b] = f[a];
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	for (int i = 0; i < maxn; i++) f[i] = i;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	for (int i = 1; i <= n; i++) {
		u()
	}
    return 0;
}

