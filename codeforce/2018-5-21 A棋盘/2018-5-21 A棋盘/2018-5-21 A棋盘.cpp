// 2018-5-21 A棋盘.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	int N;
	int a[110];
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N/2; i++) scanf("%d", &a[i]);
	sort(a, a + N/2);
	int ans1 = 0;
	for (int i = 0; i < N / 2; i++) {
		ans1 = ans1 + abs(a[i] - 1 - 2 * i);
	}
	int ans2 = 0;
	for (int i = 0; i < N / 2; i++) {
		ans2 = ans2 + abs(a[i] - 2 - 2 * i);
	}
	printf("%d\n",min(ans1,ans2));
    return 0;
}

