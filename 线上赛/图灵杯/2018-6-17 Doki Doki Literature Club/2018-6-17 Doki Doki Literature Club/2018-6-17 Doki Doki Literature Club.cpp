// 2018-6-17 Doki Doki Literature Club.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

using namespace std;
const int infi = 1e9 + 10;
int main()
{
	int n,w;
	int _max=0, _min=0;
	int sum = 0;
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		sum += tem;
		_max = max(_max, sum);
		_min = min(_min, sum);
	}
	cout << (w - (_max - _min)+1>=0? w - (_max - _min) + 1:0) << endl;
    return 0;
}

