// 2018-6-21 C. Alphabetic Removals.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int main()
{
	int n, m;
	int count = 0;
	char a[maxn];
	cin >> n >> m;
	cin >> a;
	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] != i)  continue;
			a[j] = 0;
			count++;
			if (count == m) {
				j = n;
				i = 'z' + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i] != 0) cout << a[i];
	cout << endl;
    return 0;
}

