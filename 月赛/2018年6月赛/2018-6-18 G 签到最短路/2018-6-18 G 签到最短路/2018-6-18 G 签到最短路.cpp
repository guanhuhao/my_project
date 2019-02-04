// 2018-6-18 G 签到最短路.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
const int infi = 2147483647;
int T, n, m;
typedef pair<int ,int> P;
P p[maxn];
int flag[maxn];

struct bian {
	int u, v, w;

}a[2 * maxn];
bool cmp(bian a, bian b) {
	return a.u < b.u;
}
struct cmp2 {
	bool operator() (P a,P b) {
		return a.second > b.second;      //与greater是等价的
	}
};
priority_queue<P, vector<P>, cmp2 > que;

int main()
{
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < maxn; i++) {
			p[i].first = i;
			p[i].second = infi;
		}
		p[1].second = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int tem1, tem2, tem3;
			cin >> tem1 >> tem2 >> tem3;
			a[i].u = tem1;
			a[i].v = tem2;
			a[i].w = tem3;
		}
		sort(a, a + m, cmp);
		//for (int i = 0; i <  m; i++) cout << a[i].u << " " << a[i].v << " " << a[i].w << endl;
		int head[maxn], tail[maxn];
		memset(head, -1, sizeof(head));
		for (int i = 0; i < m; i++) {
			if (head[a[i].u] == -1) head[a[i].u] = i;
			tail[a[i].u] = i;
		}
		//for (int i = 0; i <= n; i++) cout << head[i] << " " << tail[i] << endl;
		que.push(P(1,0));
		while (!que.empty()) {
			P tem = que.top();
			que.pop();
			if (flag[tem.first]) continue;
			for (int i = head[tem.first]; i <= tail[tem.first]; i++) {
				if (tem.second + a[i].w < p[a[i].v].second) {
					p[a[i].v].second = tem.second + a[i].w;
					que.push(P(a[i].v, p[a[i].v].second));
				}
			}
			flag[tem.first] = 1;
		}
		cout << p[n].second << endl;
	}
	return 0;
}