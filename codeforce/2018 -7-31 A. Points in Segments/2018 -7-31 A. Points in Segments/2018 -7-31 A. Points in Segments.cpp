// 2018 -7-31 A. Points in Segments.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		for (int j = tem1; j <= tem2; j++) a[j]++;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) if (a[i] == 0) ans++;
	cout << ans << endl;
	for (int i = 1; i <= m; i++) if(a[i]==0) cout <<i << " ";
	cout << endl;
    return 0;
}

