// 2018-7-27 C - Multiplication Puzzle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream> 
#include <cstring>
using namespace std;
int a[105];
const int inif = (int)1e8;
int rec[105][105];
int dp(int l, int r) {
	if (rec[l][r] != -1) return rec[l][r];
	if (r - l <= 1) return rec[l][r]=0;
	else {
		int mini = inif;
		for (int i = l + 1; i <= r - 1; i++)
			mini = min(mini, dp(l, i) + dp(i, r) + a[i] * a[r] * a[l]);
		return rec[l][r]=mini;
	}
}
int main()
{
	int n;
	int ans = inif;
	memset(rec, -1, sizeof(rec));
	cin >> n;
	for (int i = 0; i < n; i++) cin>>a[i];
	//for (int i = 1; i <= n - 2; i++) ans = min(ans, dp(0, n - 1));
	cout << dp(0,n-1) << endl;
    return 0;
}

