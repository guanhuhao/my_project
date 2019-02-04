// 2018-7-29 J - Piggy-Bank.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int ans[10010];
int v[550];
int w[550];
int check[10010];
const int inf = (int)1e9 + 7;
int main()
{
	int T;
	cin >> T ;
	while (T--) {
		int s, e;
		for (int i = 0; i < 10010; i++) ans[i] = inf;
		memset(check, 0, sizeof(check));
		cin >> s >> e;
		int c = e - s;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> v[i] >> w[i];
		ans[0] = 0;
		check[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1;; j*=2) {
				if (c - j*w[i] < 0) break;
				for (int k = c; k >= j*w[i]; k--) {
					if ( check[k - j*w[i] == 1]) {
						ans[k] = min(ans[k], ans[k - j*w[i]] + j*v[i]);
						check[k] = 1;
					}
				}
			}
		}
		if (ans[c] == inf)printf("This is impossible.\n");
		else printf("The minimum amount of money in the piggy-bank is %d.\n", ans[c]);
	}
    return 0;
}

