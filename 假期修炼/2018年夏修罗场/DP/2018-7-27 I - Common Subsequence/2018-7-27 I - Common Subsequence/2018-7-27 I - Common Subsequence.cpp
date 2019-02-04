// 2018-7-27 I - Common Subsequence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
string a, b;
int rec[2000][2000];
int dp(int m,int n) {
	if (m<0 || n<0) return 0;
	if (rec[m][n] != -1) return rec[m][n];
	if (a[m] == b[n]) {
		return rec[m][n]=1 + dp(m - 1, n - 1);
	}
	else return rec[m][n]=max(dp(m - 1, n), dp(m, n - 1));
}
int main()
{
	while (cin >> a >> b) {
		memset(rec, -1, sizeof(rec));
		cout << dp(a.size()-1, b.size()-1) << endl;
	}
    return 0;
}

