// 2018-7-30 A. Piles With Stones.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int sum1 = 0, sum2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		sum1 += tem;
	}
	for (int i = 0; i < n; i++)
	{
		int tem;
		cin >> tem;
		sum2 += tem;

	}
	cout << (sum1 >= sum2 ? "Yes" : "No") << endl;
    return 0;
}

