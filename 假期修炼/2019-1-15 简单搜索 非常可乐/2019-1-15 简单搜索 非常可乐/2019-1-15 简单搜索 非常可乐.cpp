// 2019-1-15 简单搜索 非常可乐.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int ans[105][105][105];
struct P {
	int a[3];
};
int c[3];
queue<P> que;
bool check(P a) {
	return ans[a.a[0]][a.a[1]][a.a[2]] == -1;
}
int cnt;
void bfs() {
	que.push(P{ c[0],0,0 });
	ans[c[0]][0][0] = 0;
	while (!que.empty()) {
		P top = que.front();
		P tem{top.a[0],top.a[1],top.a[2]};
		//cout << "text:" << top.a[0] << " " << top.a[1] << " " << top.a[2] << endl;
		que.pop();
		int dx[6] = { 0,0,1,1,2,2 },
			dy[6] = { 1,2,0,2,0,1 };
		for (int i = 0; i < 6; i++) {
			int deta= min(c[dy[i]] - top.a[dy[i]], top.a[dx[i]]);
			tem.a[dx[i]] -= deta;
			tem.a[dy[i]] += deta;
			if (check(tem)&&deta!=0) {
				que.push(tem);
				ans[tem.a[0]][tem.a[1]][tem.a[2]] = ans[top.a[0]][top.a[1]][top.a[2]] + 1;
				if ((tem.a[0] == c[0] / 2 || tem.a[1] == c[0] / 2 || tem.a[2] == c[0] / 2)&&
					(tem.a[0] == 0|| tem.a[1] == 0 || tem.a[2] == 0)) 
					cnt = min(cnt, ans[tem.a[0]][tem.a[1]][tem.a[2]]);
			}
			tem.a[dx[i]] += deta;
			tem.a[dy[i]] -= deta;
		}
	}
}
int main()
{
	while (cin >> c[0] >> c[1] >> c[2]&&c[0]) {
		cnt = 1000;
		memset(ans, -1, sizeof(ans));
		if (c[0] % 2 != 0) {
			cout << "NO" << endl;
			continue;
		}

		bfs();
		if (cnt == 1000) cout << "NO" << endl;
		else cout << cnt << endl;
	}
    return 0;
}

