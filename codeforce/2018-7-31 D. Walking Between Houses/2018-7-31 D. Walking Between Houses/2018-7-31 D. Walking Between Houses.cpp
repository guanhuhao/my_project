// 2018-7-31 D. Walking Between Houses.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, k, s;
	cin >> n >> k >> s;
	if ((n - 1)*k < s) cout << "NO" << endl;
	else {
		cout << "YES" << endl;

		int flag = 0;
		long long i;
		for ( i = 0; i < k; i++) {
			if (k - i-1 > (s - n + 1)) break;
			if (i % 2 == 0) cout << n << " ";
			else cout << 1<<" ";
			s -= (n - 1);
			flag = !flag;
		}
		if (s != 0) {
			//cout <<"hahaha"<< flag << endl << endl;
			if (flag == 1) {
				cout << n - (s - (k - i - 1)) << " ";
				long long tem = n - (s - (k - i - 1));
				s -= (s-(k - i - 1));
				for (int j = 0; j < s; j++) cout << (tem+1>n?tem=tem-1:tem=tem+1) << " ";
			}
			else {
				cout << 1 + (s - (k - i - 1)) << " ";
				long long tem = 1 + (s - (k - i - 1));
				s -= (s-(k - i - 1));
				for (int j = 0; j < s; j++) cout << (tem + 1>n ? tem=tem - 1 : tem=tem + 1 )<< " ";

			}
		}
		//cout << endl;
	}
    return 0;
}

