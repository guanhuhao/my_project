// 2018-6-10 POJ1182 食物链(2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct Animal {
	int a,b,c;
};
Animal a[50010];
int findf(int tem) {
	if (a[tem].a == tem) return tem;
	a[tem].a = findf(a[tem].a);
}
int main()
{
	for (int i = 0; i < 50010; i++) {
		a[i].a = i;
		a[i].b = a[i].c = 0;
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

		if (tem1 == 1) {

		}

	}
    return 0;
}

