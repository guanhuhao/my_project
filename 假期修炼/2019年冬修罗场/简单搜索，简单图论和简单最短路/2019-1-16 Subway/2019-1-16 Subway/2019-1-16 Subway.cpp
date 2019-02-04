// 2019-1-16 Subway.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct P {
	int num;
	double len;
};
double cal(double x1, double y1,double x2,double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
vector<P> v[205];
int vis[205];
double ans[205];
struct cmp {
	bool operator()(P a, P b) {
		return a.len > b.len;
	}
};
priority_queue<P, vector<P>, cmp> que;
void dijic() {
	for (int i = 0; i < 205; i++) ans[i] = 1e9 + 7;
	ans[0] = 0;
	que.push(P{ 0,0 });
	while (!que.empty()) {
		P top = que.top();
		que.pop();
		if (vis[top.num]) continue;
		vis[top.num] = 1;
		cout << "text:" << top.len << endl;
		for (int i = 0; i < v[top.num].size(); i++) {
			que.push(P{ v[top.num][i].num,v[top.num][i].len + top.len });
			ans[v[top.num][i].num] = min(ans[v[top.num][i].num], v[top.num][i].len + top.len);
		}
	}
}
int main()
{
	double sx, sy, ex, ey;
	freopen("in.txt", "r", stdin);
	while (cin >> sx >> sy >> ex >> ey) {
		v[0].push_back(P{ 1,cal(sx,sy,ex,ey) *6/ 1000 });
		v[1].push_back(P{ 0,cal(sx,sy,ex,ey) *6/ 1000 });
		int cnt = 2;
		double px1, py1,px2=-1,py2=-1;
		while (cin >> px1 >> py1) {
			v[cnt].push_back(P{ 0,cal(px1,py1,sx,sy)*6/1000 });
			v[0].push_back(P{ cnt,cal(px1,py1,sx,sy)*6/1000 });
			v[cnt].push_back(P{ 1,cal(px1,py1,ex,ey)*6/1000 });
			v[1].push_back(P{ cnt,cal(px1,py1,ex,ey)*6/1000 });
			if (py2 != -1 && py2 != -1) {
				v[cnt].push_back(P{ cnt - 1,cal(px1,py1,px2,py2) * 6 / 1000 });
				v[cnt-1].push_back(P{ cnt,cal(px1,py1,px2,py2) * 6 / 1000 });
			}
			while (cin >> px2 >> py2&&px2 != -1 && py2 != -1) {
				v[cnt].push_back(P{ cnt + 1,cal(px1,py1,px2,py2)/4*6/1000 });
				v[cnt+1].push_back(P{ cnt ,cal(px1,py1,px2,py2) /4*6/1000 });
				v[0].push_back(P{ cnt + 1, cal(sx, sy, px2, py2) * 6/1000});
				v[cnt+1].push_back(P{ 0, cal(sx, sy, px2, py2) * 6/1000 });
				v[1].push_back(P{ cnt + 1, cal(ex, ey, px2, py2) * 6/1000 });
				v[cnt + 1].push_back(P{ 1, cal(ex, ey, px2, py2) * 6/1000 });
				cnt++;
			}
			px2 = px1, py2 = py1;
		}
		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout <<i<<" "<<v[i][j].num<<" "<< v[i][j].len <<endl;
			}
		}
		dijic();
		printf("%d\n", (int)(ans[1] + 0.5));
	}
    return 0;
}

