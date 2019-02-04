// 2019-1-19 Jungle Roads.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n;
struct Edge {
	int u, v, len;
}edge[1010];
bool cmp(Edge a, Edge b) {
	return a.len < b.len;
}
int fat[30];
void init() {
	for (int i = 0; i < 30; i++) fat[i] = i;
}
int findf(int x) {
	return fat[x] == x ? x : fat[x] = findf(fat[x]);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin >> n&&n) {
		init();
		int ans = 0;
		int cnt = 0;
		for (int i = 0; i < n-1; i++) {
			char a;
			int b;
			cin >> a >> b;
			for (int j = 0; j < b; j++) {
				char tem;
				int len;
				cin >> tem >> len;
				edge[cnt++] = Edge{ a - 'A',tem - 'A',len };
			}
		}
		sort(edge, edge + cnt, cmp);
		for (int i = 0; i < cnt; i++) {
			int uu = findf(edge[i].u),
				vv = findf(edge[i].v);
			if (uu != vv) {
				fat[uu] = vv;
				ans += edge[i].len;
			}
		}
		cout << ans << endl;
	}
    return 0;
}

