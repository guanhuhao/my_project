// 2018-7-22  A.Plague Inc.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, m;
int a[2010][2010];
int jishu;
bool cmp (pair<int, int> a, pair<int, int> b) {
	return (a.first < b.first) || (a.first == b.first&&a.second < b.second);
}
queue<pair<int, int> > que;
void inf(int x,int y) {
	if (x + 1 <= n && a[x + 1][y] == 0) { a[x + 1][y] = 1; jishu++; que.push(pair<int, int>(x+1, y)); }
	if (x - 1 >= 1 && a[x - 1][y] == 0)   { a[x - 1][y] = 1; jishu++; que.push(pair<int, int>(x-1, y));}
	if (y + 1 <= m && a[x][y + 1] == 0)     { a[x][y + 1] = 1; jishu++; que.push(pair<int, int>(x, y+1));}
	if (y - 1 >= 1 && a[x][y - 1] == 0)   { a[x][y - 1] = 1; jishu++; que.push(pair<int, int>(x, y-1));}
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		while (!que.empty()) que.pop();
		jishu = 0;
		int num;
		memset(a, 0, sizeof(a));
		cin >> num;
		for (int i = 0; i < num; i++) {
			int x, y;
			cin >> x >> y;
			a[x][y] = 1;
			que.push(pair<int, int>(x, y));
			jishu++;
			//cout << jishu << endl;
		}
		int daxiao = n*m;
		while (jishu < daxiao) {
			if (!que.empty()) {
				int _max = que.size();
				for (int i = 0; i < _max; i++) {
					pair<int, int> tem = que.front();
					inf(tem.first, tem.second);
					que.pop();
				}
			}
		}
		int ansx = 2020, ansy = 2020;
		while (!que.empty()) {
			if(que.front().first<ansx){
				ansx = que.front().first;
				ansy = que.front().second;
			}
			else if (que.front().first == ansx&&que.front().second < ansy) {
				ansx = que.front().first;
				ansy = que.front().second;
			}
			que.pop();
		}
		cout << ansx << " " << ansy << endl;
	}
    return 0;
}

