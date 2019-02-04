// 2018-6-17 c. 养生专家.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[55];
	int ans = 0;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) continue;
		int tem = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] == a[tem]) {
				a[tem] = 0;
				tem = j;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i]) ans++;
	cout << ans << endl;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			if (flag == 0) { cout << a[i]; flag = 1; }
			else cout << " " << a[i];
		}
	}
	cout << endl;
    return 0;
}

