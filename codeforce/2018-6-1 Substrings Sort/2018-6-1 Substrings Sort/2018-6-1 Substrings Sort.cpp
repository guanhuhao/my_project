// 2018-6-1 Substrings Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
string a[110];
bool cmp(string a, string b){
	return a.size() < b.size();
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, cmp);
	int flag = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].find(a[i - 1]) == string::npos) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << a[i] << endl;
		}
	}
    return 0;
}

