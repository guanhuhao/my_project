// 2018-7-27 A - The Triangle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[110][110];
int main()
{
	int n;
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	//cout << "haha" << endl;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) a[i][j] = a[i - 1][j] + a[i][j];
			else {
				a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
			}
		}
	}
	int ans = -1;
	for (int i = 0; i < n; i++) ans = max(a[n - 1][i], ans);
	cout << ans<<endl;
    return 0;
}

