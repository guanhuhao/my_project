// 2018-7-4 A. Game Shopping.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	int a[1010];
	int b[1010];
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int j = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (j<m&&a[i] <= b[j]) {
			ans++;
			j++;
		}
	}
	cout << ans << endl;

}

