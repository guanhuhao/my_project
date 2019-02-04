// hdu 2955 Robberies.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	double dp[10005];
	int T, num,sum,money[105];
	double P, p[105];
	int i,j;
	scanf("%d", &T);
	while (T--)
	{
		for (i = 0; i < 10005; i++) dp[i] = 0;
		dp[0] = 1;
		sum = 0;
		scanf("%lf%d",&P,&num);
		for (i = 0; i < num; i++)
		{
			scanf("%d%lf", &money[i], &p[i]);
			sum = sum + money[i];
		}

		for (i = 0; i < num; i++)
			for (j = sum; j >= money[i]; j--)
				if (dp[j] < dp[j - money[i]] * (1.0 - p[i]))
					dp[j] = dp[j - money[i]] * (1.0 - p[i]);
		for (i = sum; i > 0; i--)
		{
			//printf("%lf\n", dp[i]);
			if (dp[i] > (1 - P)) break;
		}
		printf("%d\n", i);

	}
	return 0;
}
