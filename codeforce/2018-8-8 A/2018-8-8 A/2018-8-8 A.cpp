// 2018-8-8 A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int rank;
	int rec = 0;
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem1, tem2, tem3, tem4;
		cin >> tem1 >> tem2 >> tem3 >> tem4;
		int sum = tem1 + tem2 + tem3 + tem4;
		if (i == 0) rec = sum;
		else {
			if (sum > rec) ans++;
		}
	}
	cout << ans << endl;
    return 0;
}

