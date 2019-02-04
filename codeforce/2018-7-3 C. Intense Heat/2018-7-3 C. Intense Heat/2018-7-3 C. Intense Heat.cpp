// 2018-7-3 C. Intense Heat.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	double n,k;
	double ans=-100000;
	double a[5010] = {0};
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		double tem;
		cin >> tem;
		a[i] = a[i - 1] + tem;
		//cout << a[i] << endl;
	}
	for (int i = k; i <= n; i++) {
		for (int j = 1; j + i-1 <= n; j++)
		{
		
			double tem = ((a[i+j-1] - a[j-1]) / i);//	cout << tem << endl;
			ans = max(ans, tem);
		}
	}
	printf("%.8lf", ans);
    return 0;
}

