// 2018-9-4 D - Ant Trip.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int p[maxn];
int fat[maxn];
int odd[maxn];
int num[maxn];
void init() {
	memset(odd, 0, sizeof(odd));
	memset(p, 0, sizeof(p));
	memset(num, 0, sizeof(num));
	for (int i = 0; i < maxn; i++) fat[i] = i;
}
int findf(int a) {
	return a == fat[a] ? a : fat[a] = findf(fat[a]);
}
void uni(int a,int b) {
	int x = findf(a);
	int y = findf(b);
	fat[x] = fat[y];
}
int main()
{
	int n, m;
	while (cin >> n >> m) {
		init();
		for (int i = 0; i < m; i++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			p[tem1]++;
			p[tem2]++;
			uni(tem1, tem2);
			num[tem1] = num[tem2] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) findf(i);
		for (int i = 1; i <= n; i++) {
			if (p[i] % 2 == 1) odd[fat[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			if (fat[i] == i&&num[i]) ans +=( odd[i] == 0 ? 1 : odd[i] / 2);
		}
		cout << ans << endl;
	}
    return 0;
}

