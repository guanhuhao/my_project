// 2019-1-14 简单搜索 棋盘问题.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
typedef pair<int, int> P;
int cnt;
int n, k;
int visc[10], visr[10];
vector<P> v;
void dfs(int deep,int used) {
	if (deep >=v.size()||used==k) return;
	dfs(deep + 1,used);
	if (visc[v[deep].first] == 0 && visr[v[deep].second] == 0) {
		if (used == k - 1) {
			cnt++;
			return;
		}
		visc[v[deep].first] = visr[v[deep].second] = 1;
		dfs(deep + 1, used + 1);
		visc[v[deep].first] = visr[v[deep].second] = 0;
	}
	//cout << "text:" << deep << " " << used << endl;
} 
int main()
{
	char mapp[10][10];
	while (cin >> n >> k) {
		v.clear();
		cnt = 0;
		memset(visc, 0, sizeof(visc));
		memset(visr, 0, sizeof(visr));
		if (n == -1 && k == -1) break;
		for (int i = 0; i < n; i++) cin >> mapp[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mapp[i][j] == '#') v.push_back(P{i,j});
		dfs(0,0);
		cout << cnt << endl;
	}
    return 0;
}

