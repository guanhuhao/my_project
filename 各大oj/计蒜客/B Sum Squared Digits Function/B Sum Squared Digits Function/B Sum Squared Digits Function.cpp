// B Sum Squared Digits Function.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, b, sum;
		cin >> k >> b >> sum;
		int ans = 0;
		while (sum != 0) {
			ans += (sum%b)*(sum%b);
			sum /= b;
		}
		cout << k << " " << ans;
	}
    return 0;
}

