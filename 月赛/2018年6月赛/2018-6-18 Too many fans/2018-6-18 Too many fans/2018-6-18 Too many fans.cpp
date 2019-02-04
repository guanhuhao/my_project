// 2018-6-18 Too many fans.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int flag2[maxn];

set<int> s;
struct Edge {
	int u, v;
}edge[10*maxn];
struct P {
	int num;
	int flag;
	int no;
}p[maxn];
queue<P> que;
bool cmp1(Edge a, Edge b) {
	return a.u < b.u;
}
bool cmp2(P a, P b) {
	return a.num > b.num;
}
int head[maxn],tail[maxn];
void init() {
	memset(head, -1, sizeof(head));
	for (int i = 0; i < maxn; i++) {
		p[i].num = 0;
		p[i].flag = 0;
		p[i].no = i;
	};
	for(int i=1;i<=n;i++){
		s.insert(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	int ans=0;
	priority_queue<int, vector<int>, greater<int>> ans2;
	cin >> T;
	while (T--) {
		cin >> n >> m;	
		init();
		for (int i = 0; i < m; i++) cin >> edge[i].u >> edge[i].v;
		sort(edge, edge + m, cmp1);

		for (int i = 0; i < m; i++) {
			if (head[edge[i].u] == -1) head[edge[i].u] = i;
			tail[edge[i].u] = i;
			p[edge[i].u].num++;
		}
		sort(p + 1, p + n + 1, cmp2);
		for (int i = 1; i <= n; i++) {
			if (p[i].flag == 1) continue;
			ans++;
			while (!que.empty()) que.pop();
			que.push(p[i]);
			int jishu = 1;
			while (!que.empty()) {
				memset(flag2, 0, sizeof(flag2));
				P tem = que.front();
				p[tem.no].flag = 1;
				//cout << tem.num<<"hahah"<<endl;
				que.pop();
				for (int j = head[tem.num]; j <= tail[tem.num]; j++) {
					flag2[edge[j].v] = 1;
					cout << edge[j].v <<"hahah"<< endl;
				}
				//cout << s.size() <<endl<< endl;
				for (set<int>::iterator j = s.begin();j != s.end(); j++) {
					if (flag2[*j] == 1||p[*j].flag==1) continue;
					que.push(p[*j]);
					jishu++;
					p[*j].flag = 1;

					//cout << *j << endl;
					//s.erase(*j);
				}
			}
			ans2.push(jishu);
			cout << i <<"  "<< jishu << endl;
		}
		cout << ans << endl;
		int flag3 = 0;
		while (!ans2.empty()) {
			if (flag3 == 0) {
				cout << ans2.top();
				flag3 = 1;
			}
			cout << " " << ans2.top();
			ans2.pop();
		}
		cout << endl;
	}
	
	return 0;
}

