// 2019-1-21 Network.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;
const int maxn = 1e5 + 10;
int n, m;

typedef vector<int>ve;
vector<ve>edge(maxn);
int DFN[maxn], Low[maxn];
int vis[maxn];
int fat[maxn];
int bridge;
int deep[maxn];
bool mp[maxn];
int Index;
map<P, int> check;
void init() {
	for (int i = 0; i < maxn;i++) edge[i].clear();
	for (int i = 0; i < maxn; i++)fat[i] = i;
	check.clear();
	Index = 0;
	bridge = 0;
	memset(DFN, 0, sizeof(DFN));
	memset(Low, 0, sizeof(Low));
	memset(vis, 0, sizeof(vis));
	memset(mp, 0, sizeof(mp));
}
void Tarjan(int u, int pre)
{
	Low[u] = DFN[u] = ++Index;
	deep[u] = deep[pre] + 1;
	vis[u] = 1;
	for (int i = 0; i <edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (!vis[v])
		{
			Tarjan(v, u);
			fat[v] = u;
			Low[u] = min(Low[v],Low[u]);
			if (Low[v] > DFN[u])
			{
				//cout << "text:" << u << " " << v << endl;
				bridge++;
				mp[v] = 1;
				//cout << "text:" << v << endl;
			}
		}
		else if (v!=pre) Low[u] =min(Low[u], DFN[v]);
	}

}
int lca(int a, int b) {
	int ans = 0;
	/*if (DFN[a] > DFN[b]) swap(a, b);
	while (DFN[b] > DFN[a]) {
		if (check[P{b,fat[b]}]) {
			ans++;
			check[P{b,fat[b]}] = 0;
			check[P{fat[b],b}] = 0;
			//cout <<"text:"<< b << " "<<fat[b] << endl;
		}
		b = fat[b];
	}
	while (b != a) {
		if (check[P{b,fat[b]}]) {
			ans++;
			check[P{ b,fat[b] }] = 0;
			check[P{ fat[b],b }] = 0;
			//cout << "text:" << b << " " << fat[b] << endl;;
		}

		b = fat[b];
		a = fat[a];
	}*/
	/*while (b != a) {
		if (DFN[a] > DFN[b]) {
			if (check[P{ a,fat[a] }]) {
				ans++;
				check[P{ a,fat[a] }] = 0;
				check[P{ fat[a],a }] = 0;
				//cout << "text:" << a << " " << fat[a]<<endl;
			}
			a = fat[a];
		}
		else {
			if (check[P{ b,fat[b] }]) {
				ans++;
				check[P{ b,fat[b] }] = 0;
				check[P{ fat[b],b }] = 0;
				//cout <<"text:"<< b << " "<<fat[b] << endl;
			}
			b = fat[b];
		}
	}*/
	if (deep[a] > deep[b]) swap(a, b);
	while (deep[b] > deep[a]) {
		if (mp[b]) {
			ans++;
			mp[b] = 0;
			//cout <<"text:"<< b << " "<<fat[b] << endl;
		}
		b = fat[b];
	}
	while (b != a) {
		if (mp[a]) {
			ans++;
			mp[a] = 0;
			//cout << "text:" << a << " " << fat[a]<<endl;
		}
		
		if (mp[b]) {
			ans++;
			mp[b] = 0;
			//cout <<"text:"<< b << " "<<fat[b] << endl;
		}
		b = fat[b];
		a = fat[a];
	}
	return ans;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T=0;
	while (~scanf("%d%d", &n, &m)&&n) {
		if (T) printf("\n");
		init();
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		deep[0] = 1;
		Tarjan(1,1);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", ++T);
		//cout << bridge << endl;
		//for (int i = 1; i <= n; i++) cout << DFN[i] << " " << Low[i] << endl;
		//for (int i = 1; i <= n; i++) cout << "text:" << fat[i] << endl;
		while (q--) {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", bridge -= lca(a, b));
		}

	}
    return 0;
}

