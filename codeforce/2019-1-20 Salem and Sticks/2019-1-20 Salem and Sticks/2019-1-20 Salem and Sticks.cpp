// 2019-1-20 Salem and Sticks.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
double date[1010];
int main()
{
	int n;
	int ave,ave1;
	int sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> date[i];
		sum += date[i];
	}
	int rec1, rec2=10000000;
	for (int i = 1; i <= 100; i++) {
		int tem = 0;
		for (int j = 0; j < n; j++) {
			if (date[j] < i - 1) tem += i - 1 - date[j];
			else if (date[j] > i + 1) tem += date[j]-i-1;
		}
		if (rec2 > tem) rec1 = i, rec2 = tem;
	}
	
	cout << rec1 << " " << rec2 << endl;
    return 0;
}

