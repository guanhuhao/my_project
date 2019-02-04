// 2019-1-26 A Dangerous Maze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
void mul(ll &fenzi1, ll &fenmu1, ll fenzi2, ll fenmu2) {
	//cout << "text:" << fenzi1 << " " << fenmu1 << " " << fenzi2 << " " << fenmu2 << endl;
	fenzi1 = fenzi1 * fenzi2;
	fenmu1 = fenmu1 * fenmu2;
	ll d = gcd(fenzi1, fenmu1);
	fenzi1 /= d;
	fenmu1 /= d;
}
void add(ll &a1, ll &a2, ll b1, ll b2) {
	a1 *= b2;
	b1 *= a2;
	a1 += b1;
	a2 *= b2;
	ll d=gcd(a1, a2);
	a1 /= d;
	a2 /= d;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ll n,cntp=0;
		ll tem;
		ll sump=0, sumn=0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tem;
			if (tem > 0) {
				cntp++;
				sump += tem;
			}
			else sumn += -tem;
		}
		if (cntp == 0) {
			printf("Case %d: inf\n", t);
			continue;
		}
		else {
			if (cntp == n) {
				int d = gcd(cntp, sump);
				printf("Case %d: %lld/%lld\n", t,sump/d,cntp/d);
				continue;
			}
			ll fenzi = (n-cntp), fenmu =cntp;
			mul(fenzi, fenmu, sumn, n - cntp);
			add(fenzi, fenmu, sump, cntp);
			printf("Case %d: %lld/%lld\n", t, fenzi, fenmu);
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
