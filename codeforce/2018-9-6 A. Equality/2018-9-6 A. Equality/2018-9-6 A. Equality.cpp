// 2018-9-6 A. Equality.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	string str;
	int a[30] ;
	int ans = 1e6+10;
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	cin >> str;
	for (int i = 0; i < n; i++) {
		a[str[i] - 'A']++;
	}
	for (int i = 0; i < m; i++) ans = min(ans, a[i]);
	cout << ans*m << endl;
    return 0;
}

