// 2018-6-17 G. 找弟子.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int maxn = (int)2e5 + 10;
struct Stu {
	int num;
	int value;
	int count;
}a[maxn];
bool cmp1(Stu a, Stu b) {
	return a.value < b.value;
}
bool cmp2(Stu a, Stu b) {
	return a.num < b.num;
}
int main()
{
	int n, k;
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		a[i].num = i;
		cin >> a[i].value;
	}
	sort(a + 1, a + n + 1, cmp1);
	//for (int i = 0; i < n; i++)cout << a[i].value << endl;
	for (int i = 1; i <= n; i++) {
		int tem = i - 1;
		while (a[i].value == a[tem + 1].value) {
			a[i].count = tem;
			i++;
		}
		i--;
	}
	for (int i = 0; i < k; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		if (a[tem1].value > a[tem2].value) a[tem1].count--;
		else if (a[tem1].value < a[tem2].value)a[tem2].count--;
	}
	sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << a[i].count;
		else cout << " " << a[i].count;
	}
	cout << endl;
	return 0;
}