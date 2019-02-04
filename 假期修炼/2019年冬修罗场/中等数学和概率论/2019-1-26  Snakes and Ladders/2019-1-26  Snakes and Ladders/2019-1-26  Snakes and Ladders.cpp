// 2019-1-26  Snakes and Ladders.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const double eps = 1e-8;

double dp[105][105];
bool vis[105];
int  gauss(int n, int m) {                   //板子 链接->https://www.cnblogs.com/jiachinzhao/p/7204458.html  不得不说不看博客真的不会写，所以可能有点像也emmm
	int col, i, mxr, j, row;
	for (row = col = 1; row <= n && col <= m; row++, col++) {
		mxr = row;
		for (i = row + 1; i <= n; i++)
			if (fabs(dp[i][col]) > fabs(dp[mxr][col]))
				mxr = i;
		if (mxr != row) swap(dp[row], dp[mxr]);
		if (fabs(dp[row][col]) < eps) {
			row--;
			continue;
		}
		for (i = 1; i <= n; i++)///消成上三角矩阵
			if (i != row && fabs(dp[i][col]) > eps)
				for (j = m; j >= col; j--)
					dp[i][j] -= dp[row][j] / dp[row][col] * dp[i][col];
	}
	row--;
	for (int i = row; i >= 1; i--) {///回代成对角矩阵
		for (int j = i + 1; j <= row; j++) {
			dp[i][m] -= dp[j][m] * dp[i][j];
		}
		dp[i][m] /= dp[i][i];
	}
	return row;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		int n;
		cin >> n;
		dp[100][100] = 1;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			dp[a][a] = 1;
			dp[a][b] = -1;
			vis[a] = true;
		}
		for (int i = 1; i < 100; i++) {
			if (vis[i]) continue;
			int cnt = 0;
			for (int j = 1; j <=6&&j+i<=100 ; j++) {
				dp[i][j+i] = -1;
				cnt++;
			}			
			dp[i][i] = cnt;
			dp[i][101] = 6;
		}
		gauss(100, 101);
		printf("Case %d: %.7lf\n", t, dp[1][101]);

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
