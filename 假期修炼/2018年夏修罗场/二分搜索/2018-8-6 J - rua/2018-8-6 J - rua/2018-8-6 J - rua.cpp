// 2018-8-6 J - rua.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
	int a, b, n = 0; 
	int a1 = 1, a2 = 1;
	while (cin >> a >> b>>n) {
		if (a == 0 && b == 0 && n == 0) break;
		v.clear();
		v.resize(0);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		int i;
		for ( i = 3; i<=1000; i++) {
			v.push_back((v[i-1]*a+v[i-2]*b)%7);
			if (v[i] == 1 && v[i - 1] == 1) break;
		}
		v[0] = v[i - 2];
		cout << v[n % (i - 2)] << endl;;
	}
    return 0;
}

