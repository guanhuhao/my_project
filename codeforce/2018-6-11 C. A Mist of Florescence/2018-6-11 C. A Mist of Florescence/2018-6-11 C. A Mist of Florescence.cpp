// 2018-6-11 C. A Mist of Florescence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[4];
char my[55][55] = { 0 };
int _min = 200;
int rec = 0;
int tian(int i,int j) {
	for (int kind = 0; kind < 4; kind++) {
		if (kind == rec||a[kind]==0) continue;
		a[kind]--;
		my[i][j] = 'A' + kind;
		break;
	}
	return 0;
}
int main()
{

	cin >> a[0] >> a[1] >> a[2] >> a[3];
	for (int i = 0; i < 4; i++) a[i] < _min ? rec = i:0;
	int i=0, j=0;
	while (a[rec] > 1) {
		my[i][j] = 'A' + rec;
		tian(i, j + 1);
		tian(i + 1, j);
		j += 2;
		if (j >= 50) {
			i++;
			j =( (j % 50)+1)%2;
		}
		a[rec]--;
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (a[0] + a[1] + a[2] + a[3] == 1) j = 51, i = 51;
			if (my[i + 1][j] == 0 && my[i - 1][j] == 0 && my[i][j + 1] == 0 && my[i][j - 1] == 0) tian(i, j);
		}
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (my[i][j] == 0) my[i][j] = 'A' + rec;
		}
	}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			cout << my[i][j];
		}
		cout << endl;
	}
    return 0;
}

