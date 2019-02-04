// P1056 排座椅.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
struct a
{
	int num;
	int NO;
};
vector<a> c(1010), r(1010);
bool cmp(a a1, a  a2)
{
	return a1.num > a2.num;
}

int main()
{
	int M, N, K, L, D;
	int x1, y1, x2, y2;
	for (int i = 0; i < 1010; i++)c[i].NO = r[i].NO = i;
	cin >> M >> N >> K >> L >> D;
	for (int i = 0; i < D; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) c[min(y1, y2)].num++;
		else r[min(x1, x2)].num++;
	}
	stable_sort(c.begin(), c.end(), cmp);
	stable_sort(r.begin(), r.end(), cmp);	
	int ansx[1010] = {0};
	int ansy[1010] = { 0 };
	for (int i = 0; i < K; i++) ansx[i] = r[i].NO;
	for (int i = 0; i < L; i++) ansy[i]=c[i].NO;

	sort(ansx, ansx + K);
	sort(ansy, ansy + L);
	for (int i = 0; i < K; i++) cout << ansx[i] << " ";
	cout << endl;
	for (int i = 0; i < L; i++)cout << ansy[i] << " ";

    return 0;
}

