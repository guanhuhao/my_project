// 2018-7-31 C. Songs Compression.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
bool cmp(long long a, long long b) {
	return a > b;
}
int main()
{
	long long  n, cap;
	ios::sync_with_stdio(false);
	long long  sum = 0;
	cin >> n >> cap;
	for (long long  i = 0; i < n; i++) {
		long long  tem1, tem2;
		cin >> tem1 >> tem2;
		sum += tem1;
		v.push_back(tem1 - tem2);
	}
	sort(v.begin(), v.end(), cmp);
	long long  ans = 0;
	if (sum <= cap) cout << 0 << endl;
	else {
		for (long long  i = 0; i < v.size(); i++) {
			sum -= v[i];
			ans++;
			if (sum <= cap) break;
		}
		if (sum <= cap) cout << ans << endl;
		else cout << -1 << endl;
	}
    return 0;
}

