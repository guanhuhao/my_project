// 2019-1-26 Pairs Forming LCM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 1e7+10;
bool isprime[maxn];
vector<ll> pri;
void prime() {
	memset(isprime,0, sizeof(isprime));
	for (int i = 2; i < maxn; i++) {
		if (!isprime[i]) {
			pri.push_back(i);
			//cout << i << endl;
		}
		for (int j = 0; j < pri.size(); j++) {
			if (i*pri[j] > maxn) break;
			isprime[i*pri[j]] = 1;
			if (i%pri[j] == 0) break;
		}
	}

}
ll solve(ll a) {
	ll ans=1;
	for (int i = 0; i < pri.size(); i++) {
		int cnt = 0;
		while (a%pri[i] == 0) {
			cnt++;
			a /= pri[i];
		}
		ans = ans * (cnt * 2 + 1);
	}
	if (a != 1) ans *= 3;
	return ans / 2 + 1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	ll a;

	prime();	
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> a;
		printf("Case %d: %d\n", t, solve(a));
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
