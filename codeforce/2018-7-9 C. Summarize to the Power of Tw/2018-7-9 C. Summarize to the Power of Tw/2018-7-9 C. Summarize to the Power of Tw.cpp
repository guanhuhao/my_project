// 2018-7-9 C. Summarize to the Power of Tw.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 12e4 + 10;
int main()
{
	ios::sync_with_stdio(false);
	map<int, int> a;
	int in[maxn];
	int n;
	int maxi = -1;
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		a[in[i]]++;
		maxi = max(maxi, in[i]);
	}
	maxi *= 2;
	for (int i = 0; i < n; i++) {
		int tem = 2;
		for (; tem <= maxi; tem *= 2) {
			if (tem > in[i] && (a[tem - in[i]] >1||(a[tem - in[i]] ==1&&tem!=2*in[i]))) break;
			//cout << tem << endl;
		}
		if (tem > maxi) {
			ans++;
			//cout << in[i] << endl;
		}
	}
	cout << ans<<endl;
    return 0;
}

