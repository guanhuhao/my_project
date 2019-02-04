// 2018-7-28 H - 饭卡.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int price[1050];
int ans[1050][1050];
void init() {
	memset(price, 0, sizeof(price)); 
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < 1050; i++) ans[0][i] = 0;
}
int dp(int remain, int n) {
	if (n < 0 || remain <= 0) return 0;
	else if (ans[remain][n] != -1) return ans[remain][n];
	else { 
		
		 ans[remain][n] = remain-price[n]<0? dp(remain, n - 1):max(dp(remain, n - 1), dp(remain - price[n], n - 1) + price[n]);
	//	cout << remain << " " << n << " " << ans[remain][n] << endl;
		 return ans[remain][n];
	}
}
int main()
{
	int n;
	int remain;
	while (cin >> n&&n) {
		init();
		for (int i = 0; i < n; i++) cin >> price[i];
		cin >> remain;
		sort(price , price + n );
		//for (int i = 0; i < n; i++) cout << price[i] << " ";
		//cout << endl;
		if (remain < 5) cout << remain << endl;
		else cout << remain - dp(remain - 5, n - 2) - price[n-1] << endl;
	}
    return 0;
}

