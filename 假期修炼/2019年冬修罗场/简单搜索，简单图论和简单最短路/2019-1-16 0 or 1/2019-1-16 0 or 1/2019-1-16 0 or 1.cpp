// 2019-1-16 0 or 1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n;
int m[305][305];
int main()
{

	while (cin >> n) {
		int ans = 1e9+7;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> m[i][j];
		for (int i = 2; i <= n - 1; i++) ans = min(ans, m[1][i] + m[i][4]);
		ans = min(ans, m[1][4]);
		cout << ans << endl;

	}
	
		return 0;
}

