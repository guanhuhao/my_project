// 2018-10-11 B. Vasya and Isola.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, m;
	cin >> n >> m;
	ll i;
	for (i = 0; i < n; i++) {
		if (i*(i - 1)/2 >= m) break;
	}
	cout << max((ll)0, n - 2* m) << " " << max((ll)0, n - i) << endl;
    return 0;
}

