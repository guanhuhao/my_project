// 2018-7-23 B.Array(DP逆序对).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int maxn = 5050;
int dp[maxn][maxn] = {0};
long long sum[maxn] = { 0 };

int main()
{
	sum[0] = 1;
	dp[1][0] = 1;
	for (int i = 2; i <= 5000; i++) {
		for (int j = 1; j < maxn; j++) sum[j] = (sum[j]+sum[j-1])%mod;
		/*for (int j = 0; j <= 10&&i<=10; j++) cout << sum[j] << " " ;
		if (i <= 10)cout << endl;*/
		for (int j = 0; j<=5000; j++) {
			if (j - i +1> 0) dp[i][j] = ((sum[j] - sum[j - i])%mod+mod)%mod;
			else dp[i][j] = sum[j]%mod;
			//cout << j<<"  "<<i << endl;
		}
		for (int j = 1; j < maxn; j++) sum[j] = dp[i][j]%mod;
	}
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	int n, k;
	while (cin >> n >> k) {
		cout << dp[n][k]<< endl;
	}

    return 0;
}

