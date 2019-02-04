// 2018-11-9 Convex Hull.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int check[10005];
int main()
{
	memset(check, 0, sizeof(check));
	for (int i = 2; i < 100; i++) {
		for (int j = 1; j < 10000; j++) {
			if (i*i*j > 10000) break;
			check[i*i*j] = 1;
		}
	}
	long long cnt = 0;
	for (int i = 2; i < 10000; i++) {
		if (check[i] == 1) continue;
		cout << i << " " << (cnt = cnt + i*i) << endl;
	}
    return 0;
}

