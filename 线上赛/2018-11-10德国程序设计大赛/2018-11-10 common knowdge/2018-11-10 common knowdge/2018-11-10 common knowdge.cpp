// 2018-11-10 common knowdge.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
inline void write(__int128 x) {
	if (x>9) write(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
	__int128 ans = 1;
	int n;
	cin >> n;
	for (int i = 0; i<3 * n; i++) ans *= 2;
	write(ans);
	return 0;
}

