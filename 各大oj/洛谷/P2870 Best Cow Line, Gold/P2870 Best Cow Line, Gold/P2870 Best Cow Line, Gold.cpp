// P2870 Best Cow Line, Gold.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char a[30010];
	char ans[30010];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int head = 0, tail = n-1;
	int i = 0;
	while (i<n) {
		//cout << i;
		if (a[head] > a[tail]) ans[i++] = a[tail--];
		else if (a[head] < a[tail])ans[i++] = a[head++];
		else {
			char tem1[30010], tem2[30010];
			for (int j = 0; j < tail - head; j++) {
				tem1[j] = a[head + j];
				tem2[j] = a[tail - j];
			}
			tem1[tail - head] = tem2[tail - head] = '\n';
			if (strcmp(tem1, tem2) > 0) {
				for (int j = 0; j == 0 || tem1[j] == tem2[j] && tem1[j] <= tem1[j - 1]; j++)	ans[i++] = a[tail--];
			}
			else {
				for (int j = 0; j == 0 || tem1[j] == tem2[j] && tem1[j] <= tem1[j - 1]; j++)	ans[i++] = a[head++];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i != 0 && i % 80 == 0) cout << endl;
		cout << ans[i];
	}
    return 0;
}

