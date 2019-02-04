// 八皇后dfs.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int N,ans;
int  r[20],c[20], d1[40], d2[40];
int dfs(int row)
{
	if (row > N) {
		ans++;
		if (ans <= 3) {
			for (int i = 1; i <= N; i++) cout << r[i] << " ";
			cout << endl;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (c[i] != 1 && d1[row + i] != 1 && d2[row - i + N] != 1)
		{
			c[i] = d1[row + i] = d2[row - i + N] = 1;
			r[row] = i;
			dfs(row + 1);
			c[i] = d1[row + i] = d2[row - i + N] = 0;
		}
	}
	return 0;
}
int main()
{
	ans = 0;
	scanf("%d", &N);
	dfs(1);
	cout << ans << endl;
    return 0;
}

