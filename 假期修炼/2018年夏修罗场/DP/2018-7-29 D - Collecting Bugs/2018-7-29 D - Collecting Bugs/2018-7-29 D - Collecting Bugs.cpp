// 2018-7-29 D - Collecting Bugs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
double ans[1050][1050];
int main()
{
	int n, m;
	memset(ans, 0, sizeof(ans));
	cin >> n >> m;
	ans[n][m] = 0;
	for (int i = n; i >= 0; i--) {
		for (int j = m; j>=0; j--) {
			if (i == n && j == m) continue;
			ans[i][j] = (n - i)*j*(ans[i + 1][j]) + (m - j)*i*(ans[i][j + 1]) + (m - j)*(n - i)*(ans[i + 1][j + 1])+n*m;
			ans[i][j] = (ans[i][j])/(n*m - i*j);
			//ans[i][j] += 1;
		}
	}
	printf("%lf\n", ans[0][0]);
    return 0;
}

