// 2018-6-27 Codehorses T-shirts.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
map<string, int> a;
int main()
{
	int n;
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tem;
		cin >> tem;
		a[tem]++;
		num++;
	}
	for (int i = 0; i < n; i++) {
		string tem;
		cin >> tem;
		if (a[tem] > 0) {
			a[tem]--;
			num--;
		}
	}
	cout << num << endl;
    return 0;
}

