// 2018-7-1 C. Convert to Ones.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	int n, x, y;
	cin >> n >> x >> y;
	cin >> a;
	int count0 = 0, count1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') count0++;
		else count1++;
		while (a[i] == a[i + 1]) i++;
	}
	long long _min = count0;
	//cout << count1 << endl;
	if (_min == 0)cout << 0<<endl;
	else if(x < y) cout << (_min - 1)*x + y << endl;
	else cout << _min*y<<endl;
}

