// text.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;
struct Dise {
	ll num, cost;
}dise[maxn];
namespace fastIO {
#define BUF_SIZE 100000
	//fread -> read
	bool IOerror = 0;
	inline char nc() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if (p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if (pend == p1) {
				IOerror = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool blank(char ch) {
		return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
	}
	inline void read(long long int &x) {
		char ch;
		while (blank(ch = nc()));
		if (IOerror)
			return;
		for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
	}
#undef BUF_SIZE
};

int main()
{
	//freopen("in.txt", "r", stdin);
	ll sum = 0;
	std::ios::sync_with_stdio(false);
	fastIO::read(n);
	fastIO::read(m);
	for (int i = 1; i <= n; i++) {
		cin >> dise[i].num;
		sum += dise[i].num;
	}
	for (int i = 1; i <= n; i++) cin >> dise[i].cost;
	for (int i = 0; i < m; i++) {
		ll cnt = 0;
		ll cost = 0;
		ll type, num;
		cin >> type >> num;
		ll tem = min(num, dise[type].num);
		cost += tem * dise[type].cost;
		dise[type].num -= tem;
		cnt += tem;
		sum -= tem;
		while (cnt < num&&sum>0) {
			ll s = 0;
			for (int j = 1; j <= n; j++)
				if (dise[j].num) {
					s = j;
					break;
				}
			for (int j = s + 1; j <= n; j++) {
				if (dise[j].num == 0) continue;
				if (dise[j].cost < dise[s].cost) s = j;
			}
			//cout << s<<" "<<cnt<<" "<<num<<" "<<sum << endl;
			ll mini = min(num - cnt, dise[s].num);
			cost += mini * dise[s].cost;
			dise[s].num -= mini;
			cnt += mini;
			sum -= mini;
			//cout << cnt << " " << num << " " <<  sum << endl;
		}
		//	for (int j = 1; j <= n; j++) cout << dise[j].num << " ";
			//cout << endl;
			//cout << "haha" << endl;
		if (cnt != num)printf("0\n");
		else {
			printf("%I64d\n", cost);
		}
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
