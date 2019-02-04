// 2018-6-2 Points and Powers of Two.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
int main()
{
	map<long long, int> my;
	ios::sync_with_stdio(false);
	int k;
	int ans = -1, dian;
	long long jianju;
	int _max = (int)-2e9, _min = (int)2e9;
	int tem[maxn];
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tem[i];
		my[tem[i]] = 1;
		_max = max(_max, tem[i]);
		_min = min(_min, tem[i]);
	}
	for (int i = 0; i < k; i++) {
		//cout << i << endl;
		for (long long j = 1; j <= _max - _min; j = j * 2) {
			//cout << j << endl;
			//cout << _max - _min << endl;
			int count = my[tem[i] - j] + my[tem[i] + j];
			if (count > ans) {

				//cout << my[tem[i] - j] << "   " << my[tem[i] + j] << "  " << tem[i] - j << "  " << tem[i] + j << endl;
				dian = tem[i];
				jianju = j;
				ans = count;

				if (count == 2) {
					i = k;
					break;
				}

			}
		}
	}
	if (ans == 0) cout << 1 << endl << tem[0] << endl;
	else {
		cout << ans + 1 << endl;
		cout << dian << " ";
		if (my[dian + jianju] == 1) cout << dian + jianju << " ";
		if (my[dian - jianju] == 1) cout << dian - jianju;
		cout << endl;
	}

	return 0;
}

