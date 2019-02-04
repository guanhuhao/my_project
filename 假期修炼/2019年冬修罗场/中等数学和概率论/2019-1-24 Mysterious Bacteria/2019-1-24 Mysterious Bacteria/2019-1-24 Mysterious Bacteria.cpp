// 2019-1-24 Mysterious Bacteria.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int shai[maxn];
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int main()
{
	int T,t=1;
	ll a;
	ll ans;
	cin >> T;
	while (T--) {
		int cnt = 0;
		memset(shai, 0, sizeof(shai));
		cin >> a;
		ans = 0;
		bool neg = false;
		if (a < 0) {
			neg = true;
			a = -a;
		}
		for (int i = 2; i <= sqrt(a) + 1; i++) {
			while(a%i == 0) {
				cnt++;
				shai[i]++;
				a /= i;
			}
			if (!ans) ans = shai[i];
			ans = gcd(shai[i], ans);
		}	
		if (a > 1) ans = 1;
		printf("Case %d: ", t++);
		if (neg == false) {
			 cout << ans << endl;
		}
		else {
			while (ans % 2 == 0) ans /= 2;
			cout << ans << endl;
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
