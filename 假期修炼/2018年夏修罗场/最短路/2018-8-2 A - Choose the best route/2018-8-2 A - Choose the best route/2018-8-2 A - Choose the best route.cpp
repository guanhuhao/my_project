// 2018-8-2 A - Choose the best route.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int a[1010][1010];
int vis[1010];
const int INF = 1e9+7;	
int n, m, s;
void dijk(int s) {
	a[s][s] = 0;
	vis[s] = 1;
	while (1) {
		int mini = INF;
		int k = -1;
		for (int i = 0; i < 1010; i++) {
			if (vis[i] == 1) continue;
			if (a[s][i] < mini) {
				mini = a[s][i];
				k = i;
			}
		}
		//cout << "text:" << k << endl;
		if (k == -1) break;
		for (int i = 0; i < 1010; i++) {
			if (a[k][i]!=INF) {
				a[s][i] = min(a[s][i],a[s][k] + a[k][i]);
			}
		}
		vis[k] = 1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	
	while (cin >> n >> m >> s) {
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 1010; i++)
			for (int j = 0; j < 1010; j++)
				a[i][j] = INF;
		for (int i = 0; i < m; i++) {
			int tem1, tem2,tem3;
			cin >> tem1 >> tem2 >> tem3;
			//cout << "text:" << tem2 << " " << tem1 << " " << a[tem2][tem1] << endl;
			if (a[tem2][tem1] > tem3) {
				a[tem2][tem1] = tem3;
			//	cout <<"text:"<< tem2 << " " << tem1 << " " << a[tem2][tem1] << endl;
			}
		}
		dijk(s);
		int num;
		cin >> num;
		int ans = INF;
		for (int i = 0; i < num; i++) {
			int tem;
			cin >> tem;
			ans = min(ans, a[s][tem]);
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
    return 0;
}

