// 2018-8-25 A - Oulipo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;
int nex[10010];
void pre(string a) {
	int size = a.size();
	nex[1] = 0;
	int j = 0;
	for (int i = 2; i <= size; i++) {
		while (j > 0 && a[i-1] != a[j]) j = nex[j];
		if (a[j] == a[i-1]) j++;
		nex[i] = j;
	}
}

int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		string a, b;
		int ans = 0;
		cin >> a >> b;
		pre(a);
		int size = b.size();
		int j = 0;
		for (int i = 0; i < size; i++) {
			while (j > 0 && a[j] != b[i]) j = nex[j];
			if (a[j] == b[i]) j++;
			if (j == a.size()) {
				ans++;
				j = nex[j];
			}
		}
		cout << ans << endl;
	}
    return 0;
}

