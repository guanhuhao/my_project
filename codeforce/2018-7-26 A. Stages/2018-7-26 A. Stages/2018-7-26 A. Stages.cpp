// 2018-7-26 A. Stages.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b) {
	return a < b;
}
int main()
{
	priority_queue<char, vector<char>, less<>> que;
	int n, m;
	char a[55];
	cin >> n >> m;
	cin >> a;
	int ans = 0;
	sort(a, a + n, cmp);
	vector<char> v;
	for (int i = 0; i < n; i++) {
		if (i == 0 || (v.back() != a[i]&&v.back()!=a[i]-1)) v.push_back(a[i]);
	}
	//for (int i = 0; i < v.size(); i++) cout << v[i] << "  ";
	if (v.size() < m) cout << -1 << endl;
	else {
		for (int i = 0; i < m; i++) ans += v[i] - 'a' + 1;
		cout << ans << endl;
	}

    return 0;
}

