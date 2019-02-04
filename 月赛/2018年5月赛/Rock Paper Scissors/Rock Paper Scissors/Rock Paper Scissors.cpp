// Rock Paper Scissors.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
const int maxn = 100000 + 10;
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	char a1[maxn], a2[maxn];
	int n, m;
	while (cin >> n >> m) {
		int ans=0;
		scanf("%s", a1);
		scanf("%s", a2);
		for (int i = 0; i < m; i++) {
			if (a2[i] == 'R') a2[i] = 'S';
			else if (a2[i] == 'S') a2[i] = 'P';
			else a2[i] = 'R';
		}
		for (int i = 0; i < n; i++) {
			int tem = 0;
			for (int j = 0; j < m; j++) {
				if (i + j >= n) {
					break;
				}
				if (a1[i + j] == a2[j]) tem++;
			}
			ans = max(tem, ans);
		}
		printf("%d\n", ans);
	}
    return 0;
}

