// 2019-1-27 You Lose!.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 7e5 + 5;
int prime[maxn];
int check[maxn*10];
void linear_sieve() {                       //欧拉线性筛
	int tot = 0;
	memset(check, 0, sizeof(check));
	int  MAXL = 10 * maxn;
	for (int i = 2; i < MAXL; ++i) {
		if (!check[i]) prime[tot++] = i;
		for (int j = 0; j < tot; ++j) {
			if (i * prime[j] > MAXL) break;
			check[i*prime[j]] = 1;
			if (i % prime[j] == 0)break;
		}
	}
	int tem = 0;
	prime[tot] = 1e9 + 7;
	for (int i = 0; i < MAXL; ++i) {
		if (prime[tem+1] <= i) tem++;
		check[i] = prime[tem];
	}
}
int main()
{
	linear_sieve();
	int t,a;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &a);
		printf("YES\n%d\n",min(a,check[a]));
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
