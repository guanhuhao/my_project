// 2019-1-19 E - Arctic Network.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct P {
	double x, y;
}p[505];
struct Edge{
	int u, v ;
	double len;
}edge[300000];
bool cmp(Edge a, Edge b) {
	return a.len < b.len;
}
int fat[505];
vector<double>ans;
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void init() {
	for (int i = 0; i < 505; i++) fat[i] = i;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		init();
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> p[i].x >> p[i].y;
		int cnt = 0;
		for (int i = 0; i < m; i++)
			for (int j = i + 1; j < m; j++)
				edge[cnt++] = Edge{i,j, (p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y) };
		sort(edge, edge + cnt, cmp);
		int count = 0;
		double ans = 0;
		for (int i = 0; i < cnt&&count != m - n; i++) {
			int x = findf(edge[i].u),
				y = findf(edge[i].v);
			if (x != y) {
				fat[x] = y;
				ans = edge[i].len;
				//cout <<"text:" <<sqrt(ans) << endl;
				count++;
			}
		}
		printf("%.2f\n", sqrt(ans));
	}
    return 0;
}

