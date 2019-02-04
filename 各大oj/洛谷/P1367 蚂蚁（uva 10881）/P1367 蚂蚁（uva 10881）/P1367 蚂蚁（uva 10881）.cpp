// P1367 蚂蚁（uva 10881）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
struct Ant
{
	int no;
	int r;
	int pos;
};
bool cmp(Ant &a, Ant &b)
{
	return a.pos < b.pos;
}
int main()
{
	Ant ant[maxn];
	int t, n;
	ios::sync_with_stdio(false);
	map<int, int> my;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		ant[i].no = i;
		cin >> ant[i].pos >> ant[i].r;
	}
	sort(ant, ant + n, cmp);
	for (int i = 0; i < n; i++)	my[ant[i].no]=i;
	for (int i = 0; i < n; i++) ant[i].pos = ant[i].pos + t*ant[i].r;
	sort(ant, ant + n, cmp);
	for (int i = 0; i < n - 1; i++) if (ant[i].pos == ant[i + 1].pos) ant[i].r= ant[i + 1].r = 0;
	for (int i = 0; i < n; i++)
	{

		cout << ant[my[i]].pos << " "<< ant[my[i]].r << endl;
	}

	return 0;
}

