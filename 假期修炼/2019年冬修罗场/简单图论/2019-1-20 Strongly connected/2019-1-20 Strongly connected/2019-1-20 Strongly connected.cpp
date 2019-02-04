// 2019-1-20 Strongly connected.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> edge[maxn];
long long n, m;
vector<long long> ans;
int vis[maxn];
int DFN[maxn], LOW[maxn];
int in[maxn], out[maxn];
int dp[maxn];
int index;
int fat[maxn];
int belong;
vector<int> S;
void init() {
	index = 0;
	belong = -1;
	for (int i = 0; i < maxn; i++) edge[i].clear();
	memset(DFN, 0, sizeof(DFN));
	memset(LOW, 0, sizeof(LOW));
	memset(vis, 0, sizeof(vis));
	memset(dp, 0, sizeof(dp));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	ans.clear();
}
void dfs(int deep,int value) {
	if (deep >= ans.size()||dp[n/2]) return;
	dp[value] = 1;
	dfs(deep + 1, value);
	if(value<=n/2) dfs(deep + 1, value + ans[deep]);
}
void tarjan(int s) {             //对了这个是板子改了一点 但网址忘了
	int i, p;
	DFN[s] = LOW[s] = ++index;
	S.push_back(s);
	vis[s] = 1;
	for (i = 0; i<edge[s].size(); i ++) {
		int v = edge[s][i];
		if (!DFN[v]) {
			tarjan(v);
			LOW[s] = min(LOW[s], LOW[v]);
		}
		else if (vis[v]) LOW[s] = min(LOW[s], DFN[v]);
	}
	if (DFN[s] == LOW[s]) {
		int cnt=0;
		belong++;
		do {
			p = S.back();
			S.pop_back();
			vis[p] = 0;
			fat[p] = belong;
			cnt++;

		} while (s != p);
		if(cnt)ans.push_back(cnt);
	}
	return;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T, CASE = 1;;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%lld%lld", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) 
			if(!DFN[i])tarjan(i);
		/*cout << "text:" << endl;
		for (int i = 0; i < ans.size(); i++)  cout << ans[i] << "  ";
		cout << endl;*/
		long long maxi = 0,tem=0;
		//for (int i = 0; i <= n; i++) cout << i << " " << dp[i] << endl;
		//for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				if (fat[edge[i][j]] != fat[i]) {
					out[fat[i]]++;
					in[fat[edge[i][j]]]++;
				}
			}
		}
		/*for (int i = 0; i < ans.size(); i++) {
			cout << "text:" << i << " " << in[i] << " " << out[i] << endl;
		}*/
		for (int i = 0; i < ans.size(); i++) {
			if (in[i] == 0 || out[i] == 0) {
				tem = ans[i];
				maxi = max(maxi,(n - tem)*(n - tem - 1) + tem * (tem - 1) + tem * (n - tem));
			}
		}
		if(ans.size()==1) maxi = m - 1;
		printf("Case %d: %lld\n", CASE++, maxi - m);
	}

    return 0;
}




