// 2019-1-26 Just another Robbery.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef pair<int, double> P;
P a[110];
const int maxn = 10000+7;
double dp[maxn];
double p;
int n;
int ans;

bool cmp(P a, P b) {
	return a.first / a.second > b.first / b.second;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < maxn; i++) dp[i] = -1;
		ans = 0;
		cin >> p >> n;
		dp[0] = 0;
		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		for (int i = 0; i < n; i++) {
			for (int j = 10000; j >= a[i].first; j--) {
				if (dp[j-a[i].first] != -1) {
					
					if (dp[j] == -1)  dp[j] = 1 - (1 - dp[j - a[i].first])*(1 - a[i].second);
					else dp[j] = min(dp[j], 1 - (1 - dp[j - a[i].first])*(1 - a[i].second));
					//cout << j<<" "<<dp[j]<<" "<< dp[j - a[i].first] << endl;
				}
			}
		}
		for (int i = 10000; i >= 0; i--) {
			if (dp[i] != -1 && dp[i] < p) {
				ans = i;
				break;
			}
		}
		//for (int i = 0; i < 10; i++) cout << dp[i] << " ";
		//cout << endl;
		printf("Case %d: %d\n", t, ans);
		
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
