// 2018-7-30 D. Chemical table.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct N {
	int x, y;
}node[maxn];
int head[maxn];
int tail[maxn];
int a[maxn];
int lie[maxn];
bool cmp(N a, N b) {
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}
int main()
{
	int n, m, num;
	memset(a, 0, sizeof(a));
	memset(head, -1, sizeof(head));
	memset(tail, -1, sizeof(tail));
	memset(lie, 0, sizeof(lie));
	cin >> n >> m >> num;
	for (int i = 0; i < num; i++) {
		cin >> node[i].x >> node[i].y;
		lie[node[i].x]++;
	}
	sort(node, node + num, cmp);
	for (int i = 0; i < num; i++) {
		if (head[node[i].x] == -1)head[node[i].x] = i;
		tail[node[i].x] = i;
	}
	for (int i = 0; node[i].x == 1; i++) a[node[i].y] = 1;
	for (int i = 2; i <=n; i++) {
		if (head[i] == -1) continue;
		int flag = 0;
		for (int j = head[i]; j <= tail[i]; j++) {
			if (a[node[j].y] == 1) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			for (int j = head[i]; j <= tail[i]; j++) {
				a[node[j].y] = 1;
			}
		}
		
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		if (a[i] == 0) ans++;
	for (int i = 2; i <= n; i++) if (lie[i] == 0)ans++;
	cout << ans<<endl;
    return 0;
}

