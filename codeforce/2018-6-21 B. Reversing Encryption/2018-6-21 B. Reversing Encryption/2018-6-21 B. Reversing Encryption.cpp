// 2018-6-21 B. Reversing Encryption.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int n;
	cin >> n>>a;
	for (int i = 2; i <= n; i++) {
		if (n%i != 0) continue;
		for (int j = 0; j < (double)(i-1)/2; j++) {
			char tem;
			tem = a[j];
			a[j] = a [i - j-1];
			a[i - j-1] = tem;
		}
		//cout << a << endl;
	}
	cout << a << endl;
    return 0;
}

