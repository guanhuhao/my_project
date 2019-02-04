// 2018 5-29 Three displays.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
const int inif = (int)5e9;
bool cmp(int a, int b) {
	return a < b;
}
int main()
{
	int n;
	int size[maxn], cost[maxn];
	int tem1[maxn];
	int flag[maxn] = { 0 };
	int tail;
	int ans = inif;
	int mini=inif;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &size[i]);
	for (int i = 0; i < n; i++) scanf("%d", &cost[i]);
	for (int i = 0; i < n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			int tem2=i;
			tem1[0] = cost[i];
			tail = 0;
			int cost1, cost2;
			cost1 = cost2= inif;
			for (int j = i+1; j < n; j++) {
				if (size[j] > size[tem2]) {
					tail++;
					flag[j] = 1;
					tem1[tail] = cost[j];
					tem2 = j;
				}
			}
			//for (int j = 0; j <= tail; j++) cout << tem1[j] << endl;
			if (tail < 2) continue;
			sort(tem1, tem1 + tail+1,cmp);
			//for (int j = 0; j <= tail; j++) cout << tem1[j] << endl;
			ans = tem1[1] + tem1[2] + tem1[0];

		}
	}
	if (ans == inif) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}

