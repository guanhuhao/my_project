// 2018-8-4 再续畅通工程.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> island;
island land[205];
struct Edge {
	Edge(int ss = 0, int ee = 0, double vv = 0) { s = ss, e = ee; v = vv; }
	int s, e;
	double v;
}edge[10010];
bool cmp(Edge a, Edge b) {
	return a.v<b.v;
}
int fat[205];
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
void uni(int a, int b) {
	int x = findf(a);
	int y = findf(b);
	if (x != y)fat[x] = fat[y];
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int size = 0;
		for (int i = 0; i<205; i++) fat[i] = i;
		for (int i = 0; i<n; i++) cin >> land[i].first >> land[i].second;
		for (int i = 0; i<n; i++) {
			for (int j = i + 1; j<n; j++) {
				double x = land[i].first - land[j].first;
				double y = land[i].second - land[j].second;
				double len = sqrt(x*x + y*y);

				if (len<10 || len>1000) continue;
				edge[size].s = i+1;
				edge[size].e = j+1;
				edge[size++].v = len;
			}
		}
		sort(edge, edge+size, cmp);
		double ans = 0;
		for (int i = 0; i<size; i++) {
			if (findf(edge[i].s) != findf(edge[i].e)) {
				ans += edge[i].v * 100;
				uni(edge[i].s, edge[i].e);
			}
		}
		for (int i = 0; i <= n; i++) {
			findf(i);
		}
		int cnt = 0;
		//for (int i = 1; i <= n; i++) cout << fat[i] << " ";
		//cout << endl;
		for (int i = 1; i <= n; i++)
			if (fat[i] == i) cnt++;
		if (cnt>1) cout << "oh!" << endl;
		else cout << fixed << setprecision(1) << ans << endl;
	}
	return 0;
}

