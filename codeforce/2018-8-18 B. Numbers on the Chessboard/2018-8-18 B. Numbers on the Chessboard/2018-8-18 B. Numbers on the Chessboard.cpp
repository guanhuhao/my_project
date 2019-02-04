// 2018-8-18 B. Numbers on the Chessboard.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		long long x, y;
		cin >> x >> y;
		long long ans = 0;
		if (n % 2 == 1) {
			long long tem = (x-1)*n + y;
			if ((tem) % 2 == 1) {
				ans = (tem + 1) / 2;
			}
			else {
				ans = (n*n + 1) / 2 + tem / 2;
			}
		}
		else {
			long long tem = (n / 2)*(x - 1) + (y + 1) / 2;
			if ((x + y) % 2 == 0) ans = tem;
			else ans = n*n / 2 + tem;
		}
		cout << ans << endl;
	}
    return 0;
}

