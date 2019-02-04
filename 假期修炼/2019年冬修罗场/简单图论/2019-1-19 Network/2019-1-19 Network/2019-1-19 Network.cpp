// 2019-1-19 Network.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
struct Edge {
	int u, v;
}edge[105];
int n, num;
int cnt = 0;
int fat[105];
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void uni(int x, int y) {
	int xx = findf(x),
		yy = findf(y);
	if (xx != yy) fat[xx] = yy;
}
int built(int x) {
	int ans = 0;
	for (int i = 1; i <= n; i++) fat[i] = i;
	for (int i = 0; i < cnt; i++) {
		if(edge[i].u!=x&&edge[i].v!=x)
			uni(edge[i].u, edge[i].v);
	}
	for (int i = 1; i <= n; i++)
		if (fat[i] == i) ans++;
	return ans;
}
int main()
{
	while (cin >> n&&n) {
		cnt=0;
		memset(edge, 0, sizeof(edge));
		while (cin >> num&&num) {
			char flag='a';
			while (flag != '\n') {
				int tem;
				cin >> tem;
				edge[cnt++] = Edge{ num,tem };
				flag = getchar();
			}
		}
		int tem = built(0);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (built(i) - tem >= 2) ans++;
		}
		cout << ans << endl;
	}
    return 0;
}

