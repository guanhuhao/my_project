// 2018-8-24 B - Toy Storage.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
struct Edge {
	double x1, y1, x2, y2;
}edge[1010];
double check(Edge a, double x, double y) {
	double flag = - (a.y2 - a.y1);
	//if (x == 65) cout << "haha:"  << -(a.y2 - a.y1)<<" "<<(x - a.x1) << endl;
	return ((y - a.y1)*(a.x2 - a.x1) - (a.y2 - a.y1)*(x - a.x1))*flag;
}
int area[1010];
int ans[1010];
bool cmp(Edge a, Edge b) {
	return a.x1 < b.x1;
}
int main()
{
	int n, m;
	double x1, x2, y1, y2;
	while (cin >> n >> m >> x1 >> y1 >> x2 >> y2&&n) {
		memset(area, 0, sizeof(area));
		memset(edge, 0, sizeof(edge));
		memset(ans, 0, sizeof(ans));
		edge[0] = { x1,y1,x1,0 };
		edge[n + 1] = { x2,y2 + 1,x2,y2 };
		for (int i = 1; i <= n; i++) {
			double tem1,tem2;
			cin >> tem1 >> tem2;
			edge[i] = { tem1,y1,tem2,y2 };
		}
		sort(edge, edge + 2+n,cmp);
		for (int i = 0; i < m; i++) {
			double x, y;
			cin >> x >> y;
			int l=-1, r=n+2;
			while (r - l > 1) {
				int mid = (r + l) / 2;
				//cout << "text1:" << mid <<" "<<r<<" "<<l<< " " << check(edge[mid], x, y) << endl;
				if (check(edge[mid], x, y) < 0) r = mid;
				else l = mid;
			}
			//cout << "text:" << l << " " << r << endl;
			area[l]++;
		}
		printf("Box\n");
		for (int i = 0; i < 1010; i++) {
			ans[area[i]]++;
		}
		for (int i = 1; i < n + 1; i++) {
			if (ans[i] == 0)continue;
			printf("%d: %d\n", i, ans[i]);
		}

	}
    return 0;
}

