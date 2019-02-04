// 2018-7-27 B - Cash Machine.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int ans[10][100010];
int num[11], mian[11];
int flag = 0;
int maxi;
void init() {
	memset(num, 0, sizeof(num));
	memset(mian, 0, sizeof(mian));
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < 10; i++) ans[i][0] = 0;
	flag = 0;
}

int dp(int n,int cash) {
	if (n == -1) return 0;
	if (ans[n][cash] != -1) return ans[n][cash];
	else {
		for (int k = 0; k <= num[n]; k++) {
			if (cash - k*mian[n]<0||ans[n][cash]==cash) break;
			ans[n][cash] = max(ans[n][cash], dp(n - 1, cash - k*mian[n]) + k*mian[n]);
			if (flag || ans[n][cash]==maxi) {
				flag = 1;
				return maxi;
			}
		}
		return ans[n][cash];
	}
	
}
int main()
{
	int cash,n;
	while (cin >> cash>>n) {
		init();
		maxi = cash;
		for (int i = 0; i < n; i++) cin >> num[i] >> mian[i];
		cout << dp(n-1,cash) << endl;
	
	}
    return 0;
}

