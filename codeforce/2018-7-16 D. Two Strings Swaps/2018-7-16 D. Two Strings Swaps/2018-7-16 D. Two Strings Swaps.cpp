// 2018-7-16 D. Two Strings Swaps.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string a, b;
	cin >> n;
	cin >> a >> b;
	int num = n / 2;
	int ans = 0;
	for (int i = 0; i < num; i++) {
		if (b[i] == b[n - i - 1]) {
			if (a[i] == a[n - 1 - i]) {
				if (a[i] == b[n - i - 1]) ans += 2;
			}
			else ans++;
		}
		else {
			if (a[i] == a[n - 1 - i]) {
				if (a[i] == b[i] || b[n - i - 1] == a[i]) ans++;
				else ans += 2;
			}
			else if ((a[i] == b[i] && a[n - 1 - i] == b[n - 1 - i])||(a[n - 1 - i] == b[i] && a[i] == b[n - 1 - i]));
			else if (a[i] == b[i] || a[i] == b[n - 1 - i] || a[n - 1 - i] == b[i] || a[n - 1 - i] == b[n - 1 - i]) ans++;
			else ans += 2;
		}
	}
	if (n % 2 == 1) {
		if (a[num] != b[num ]) ans++;
	}
	cout << ans<<endl;
    return 0;
}

