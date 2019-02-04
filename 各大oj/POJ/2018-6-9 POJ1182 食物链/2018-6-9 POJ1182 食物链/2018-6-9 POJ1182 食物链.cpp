// 2018-6-9 POJ1182 食物链.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Animal {
	int kind;
	int root;
};
Animal a[50010];
int findf(int root) {
	if (a[root].root == root) return root;
	a[root].root = findf(a[root].root);
	a[root].kind = a[a[root].root].kind;
	return a[root].root;
}
int main()
{
	for (int i = 0; i < 50010; i++) {
		a[i].kind = -1;
		a[i].root = i;
	}
	int n, k;
	int ans = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int tem1, tem2, tem3;
		cin >> tem1 >> tem2 >> tem3;
		if (tem2 > n || tem3 > n || tem2 <= 0 || tem3 <= 0) {
			ans++;
			continue;
		}
		findf(tem2);
		findf(tem3);

		if (tem1 == 1) {
			if (a[tem2].kind == -1 || a[tem3].kind == -1 || a[tem2].kind == a[tem3].kind) {  //判断是否为同类
				a[tem2].root = a[tem3].root;
				a[tem2].kind = a[tem3].kind = max(a[tem2].kind, a[tem3].kind);
			}
			else ans++;
		}

		if (tem1 == 2) {
			if (a[tem2].kind == -1 && a[tem3].kind == -1) {
				a[a[tem2].root].kind = 0;
				a[a[tem3].root].kind = 1;
			}
			else if (a[tem2].kind == -1) a[a[tem2].root].kind = (a[tem3].root + 2) % 3;
			else if (a[tem3].kind == -1) a[a[tem3].root].kind = (a[tem2].root + 1) % 3;
			else if ((a[tem2].kind + 1) % 3 != a[tem3].kind) ans++;
		}

	}
	cout << ans << endl;;
    return 0;
}

