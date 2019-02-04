// 2018-7-27 B - The Necklace.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int du[55];
int a[55][55];
int fat[55];
int vis[55];
void init() {
	memset(du, 0, sizeof(du));
	memset(a, 0, sizeof(a));
	for (int i = 0; i < 55; i++) fat[i] = i;
	memset(vis, 0, sizeof(vis));
}
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void unionnode(int a, int b) {
	int x = findf(a), y = findf(b);
	if (x != y) fat[x] = fat[y];
}
void print(int x) {
	for (int i = 0; i < 55; i++) {
		if (a[x][i]) {
			a[x][i]--;
			a[i][x]--;
			print(i);
			printf("%d %d\n", i, x);
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int num;
		init();
		cin >> num;
		for (int j = 0; j < num; j++) {
			int tem1, tem2;
			cin >> tem1 >> tem2;
			du[tem1]++, du[tem2]++;
			a[tem1][tem2]++;
			a[tem2][tem1]++;	
			vis[tem1] = vis[tem2] = 1;
			unionnode(tem1, tem2);
		}
		printf("Case #%d\n", i);
		int flag = 0;
		for (int j = 0; j < 55; j++)
			if (du[j] % 2 != 0) {
				printf("some beads may be lost\n\n");
				flag = 1;
				break;
			}

		if (flag == 1) continue;

		for (int j = 0; j < 55; j++) findf(j);
		int cnt = 0;
		for (int j = 0; j < 55; j++) {
			if (vis[j] && fat[j] == j) cnt++;
		}
		if (cnt > 1) {
			printf("some beads may be lost\n\n");
			continue;
		}
		int p, n;
		for (int j = 0; j < 55; j++) {
			for (int k = 0; k < 55; k++) {
				if (a[j][k]) {
					p = j, n = k;
					j = 56;
					break;
				}
			}
		}
		print(p);
		cout << endl;
	}
    return 0;
}

