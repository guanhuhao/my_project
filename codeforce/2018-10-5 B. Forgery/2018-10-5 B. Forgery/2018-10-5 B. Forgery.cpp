// 2018-10-5 B. Forgery.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
char a[1010][1010];
int n, m;
bool check2(int x, int y) {
	int temx[8] = { -1,-1,-1,0,0,1,1,1 };
	int temy[8] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 0; i < 8; i++) {
		if (x + temx[i] < n&&x + temx[i] >= 0 && y + temy[i] < m&&y + temy[i] >= 0) {
			if (a[x + temx[i]][y + temy[i]] != '#') return false;
		}
		else return false;
	}
	return true;
}
bool check(int x, int y) {
	int temx[8] = { -1,-1,-1,0,0,1,1,1 };
	int temy[8] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 0; i < 8; i++) {
		if (x + temx[i] < n&&x + temx[i] >= 0 && y + temy[i] < m&&y + temy[i] >= 0) {
			if (check2(x + temx[i], y + temy[i]) == true) return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#') {
				if (check(i, j) == false) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
    return 0;
}

