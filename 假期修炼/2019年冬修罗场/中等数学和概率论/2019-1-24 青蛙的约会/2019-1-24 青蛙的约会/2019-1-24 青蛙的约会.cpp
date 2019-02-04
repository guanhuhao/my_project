// 2019-1-24 青蛙的约会.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0 ? a:gcd(b, a%b);
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
	ll d, x1, y1;
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		d = exgcd(b, a % b, x1, y1);
		x = y1;
		y = x1 - a / b * y1;
	}
	return d;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	ll a, b, c, d, e;
	while (cin >> a >> b >> c >> d >> e) {	
		ll x, y;
		ll tem1 = c<d?d-c:c-d;
		ll tem2 = c<d?a-b:b-a;
		tem2 = (tem2 + e) % e;
		int d= exgcd(tem1, e, x, y);
		//cout << "text:" << tem1<<" " << tem2 << endl;
		if (tem2%d==0) {
			x *= tem2 / d;
			e /= d;
			while (x < 0) x += e;
			cout << x%e << endl;
		}
		else cout << "Impossible" << endl;
	}
	return 0;
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
