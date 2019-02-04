// 2019-1-20 C. Ayoub and Lost Array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
ll dp[3][maxn];
int main()
{
	ll n, l, r;
	cin >> n >> l >> r;
	for (int i = l; i <= r; i++)
		if (i % 3 == 0) {
			dp[0][1] = 1 + (r - i) / 3;
			break;
		}
	for (int i = l; i <= r; i++)
		if (i % 3 == 1) {
			dp[1][1] = 1 + (r - i) / 3;
			break;
		}
	for (int i = l; i <= r; i++)
		if (i % 3 == 2) {
			dp[2][1] = 1 + (r - i) / 3;
			break;
		}
	//cout << "text:" << dp[0][1] << " " << dp[1][1] << " " << dp[0][1] << endl;
	/*for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[0][i] = ((dp[0][j] * dp[0][i - j])%mod+ (dp[1][j] * dp[1][i - j])%mod)%mod;
			dp[1][i] = ((dp[0][j] * dp[1][i - j])%mod+ (dp[2][j] * dp[2][i - j])%mod)%mod;
			dp[2][i] = ((dp[0][j] * dp[2][i - j])%mod+ (dp[1][j] * dp[1][i - j])%mod)%mod;
		}
	}*/
	for (int i = 2; i <= n; i++) {
		dp[0][i] = ((dp[0][i-1] * dp[0][1]) % mod + (dp[1][i-1] * dp[2][1]) % mod + (dp[2][i-1]*dp[1][1])%mod) % mod;
		dp[1][i] = ((dp[0][i-1] * dp[1][1]) % mod + (dp[2][i-1] * dp[2][1]) % mod + (dp[1][i-1]*dp[0][1])%mod) % mod;
		dp[2][i] = ((dp[0][i-1] * dp[2][1]) % mod + (dp[1][i-1] * dp[1][1]) % mod + (dp[2][i-1]*dp[0][1])%mod) % mod;
	}
	//for (int i = 1; i <= n; i++) cout << i << " " << dp[0][i] << endl;
	cout << dp[0][n] << endl;

    return 0;
}

