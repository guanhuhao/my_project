// 2018-7-31 G - Stripies.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <queue>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
priority_queue<double>que;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double tem;
		cin >>tem;
		que.push(tem);
	}
	while (!que.empty()&&que.size()!=1) {
		double tem1 = que.top();
		que.pop();
		double tem2 = que.top();
		que.pop();
		que.push(2 * sqrt(tem1*tem2));
	}
	printf("%.3lf\n",que.top());
    return 0;
}

