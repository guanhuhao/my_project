// 2018-8-8 B. The Bits.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int num[2];
	memset(num, 0, sizeof(num));
	string a, b;
	cin >> n;
	cin >> a >> b;
	long long  ans = 0;
	for (int i = 0; i < n; i++) {
		num[a[i] - '0']++;
	}
	for (int i = 0; i < n; i++) {
		if (b[i] == '0') {
			ans += num[(a[i] - '0'+1) % 2];
			num[a[i] - '0']--;
		}
	}
	cout << ans << endl;
    return 0;
}

