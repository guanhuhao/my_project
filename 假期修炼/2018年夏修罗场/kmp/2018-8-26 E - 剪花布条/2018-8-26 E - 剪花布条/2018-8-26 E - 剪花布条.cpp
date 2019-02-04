// 2018-8-26 E - 剪花布条.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int nex[1010];
void pre(string a) {
	int j = 0;
	int n = a.size();
	nex[0] = -1;
	nex[1] = 0 ;
	for (int i = 2; i <= n; i++) {
		while (j > 0 && a[i - 1] != a[j]) j = nex[j];
		if (a[i - 1] == a[j]) j++;
		nex[i] = j;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	string a,b;
	while (cin >> a) {
		if (a == "#") break;
		cin >> b;	
		int n = a.size();
		int m = b.size();
		pre(b);
		int j = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			while (j > 0 && b[j]!=a[i]) j = nex[j];
			if (b[j] == a[i])j++;
			if (j == m) {
				ans++;
				j = 0;
			}
		}
		cout << ans << endl;
	}
    return 0;
}

