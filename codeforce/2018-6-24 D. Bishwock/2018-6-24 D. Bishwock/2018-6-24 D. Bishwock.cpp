// 2018-6-24 D. Bishwock.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0') a[i] = 1;
		else a[i] = 0;
		if (b[i] == '0')b[i] = 1;
		else b[i] = 0;
	}
	for (int i = 0; i+1 < a.size(); i++) {
		if (a[i] + a[i + 1] + b[i] + b[i + 1] == 3) {
			//cout << i << endl;
			ans++;
			i++;
		}
		else if (a[i] + a[i + 1] + b[i] + b[i + 1] == 4) {
			ans++;
			i++;
			if (i+1<a.size()&&a[i + 1] + b[i + 1] == 2) {
				ans++;
				i++;
			}
		}
	}
	cout << ans << endl;
    return 0;
}

