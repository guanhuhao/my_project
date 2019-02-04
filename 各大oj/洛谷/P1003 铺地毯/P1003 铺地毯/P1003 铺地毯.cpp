// P1003 铺地毯.cpp: 定义控制台应用程序的入口点。
//https://www.luogu.org/problemnew/show/P1003

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e4 + 10;
int main()
{
	int a[maxn], b[maxn], g[maxn], w[maxn],n;
	int x, y;
	int ans;
	//fstream fp;
	//fp.open("carpet.in",ios::in);
	cin >> n;
	//cout << n;
	for (int i = 0; i < n; i++) { cin >> a[i] >> b[i] >> g[i] >> w[i]; }
	cin >> x >> y;
	for (int i = n - 1; i > -1; i--) {
		if (x >= a[i] && x <= a[i] + g[i] && y >= b[i] && y <= b[i] + w[i]) {
			ans = i + 1;
			break;
		}
		else if (i == 0) ans = -1;
	}
	//fstream out;
	//out.open("carpet.out", ios::out);
	cout << ans << endl;

}

