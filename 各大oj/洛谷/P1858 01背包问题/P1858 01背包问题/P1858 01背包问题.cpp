// P1858 01背包问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int inif = (int)1e9;
int main()
{
	int dp[210];
	int K, V, N;
	ios::sync_with_stdio(false);
	cin >> K >> V >> N;
	for (int i = 0; i < N; i++) dp[i] = inif;
	for (int i = 0; i < N; i++) {
		int cost, v;
		cin >> v >> cost;
	}
    return 0;
}

