// 2018-9-4 A - Snowflake Snow Snowflakes.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
long long mod = 1e9 + 7;
struct point {
	ll sum;
	ll squa;
}p[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll sum = 0;
		ll squa = 0;
		for (int j = 0; j < 6; j++) {
			int tem;
			cin >> tem;
			sum += sum;
			squa += tem*tem;
		}
		p[i].sum = sum;
		p[i].squa = squa;
	}
    return 0;
}

