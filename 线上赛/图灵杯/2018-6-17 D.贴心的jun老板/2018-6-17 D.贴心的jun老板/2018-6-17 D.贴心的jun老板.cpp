// 2018-6-17 D.贴心的jun老板.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int ans=0;
	char a[110];
	cin >> n;
	cin >> a;
	for (int i = 0; i+2 < n; i++) {
		if (a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == '6') {
			i = i + 2;
			for (int j = i; j < n; j++) {
				if (a[j] == '6') ans++;
				else break;
				i = j;
			}
	
		}
	}
	cout << ans << endl;
    return 0;
}

