// 2018-10-5 C.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
int main()
{
	int n;
	int cnt = 0;
	int k = 1;
	cin >> n;
	if (n == 3) {
		cout << "1 1 3" << endl;
		return 0;
	}
	if (n % 2 == 1) {
		cout << 1 << " ";
		n = n - 1;
	}
	while (cnt != n) {
		if (n - cnt == 3) {
			cout << k << " " << k << " " << 3*k << endl;
			return 0;
		}
		int tem = ((n - cnt) + 1) / 2;
		for (int i = 0; i < tem; i++) {
			cout << k << " ";
		}
		k *= 2;
		cnt += tem;
	}
	cout<<endl;
    return 0;
}

