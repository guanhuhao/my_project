// 2019-1-15 Mine Sweeper.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char mapp1[15][15];
char mapp2[15][15];
char ans[15][15];
int n;
int check(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int cnt(int x,int y) {
	int num = 0;
	int dx[8] = { 1,1,1,0,0,-1,-1,-1 },
		dy[8] = { 1,0,-1,1,-1,1,0,-1 };
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i],
			yy = y + dy[i];
		if (check(xx,yy)&&mapp1[xx][yy] == '*') num++;
	}
	if (mapp1[x][y] == '*') num = -1;
	return num;
}
int main()
{
	while (cin >> n) {
		int flag = 0;
		for (int i = 0; i < n; i++) cin >> mapp1[i];
		for (int i = 0; i < n; i++) cin >> mapp2[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mapp2[i][j] == 'x') {
					ans[i][j] = cnt(i, j) + '0';
					if (cnt(i, j) == -1) flag = 1;
				}
				else ans[i][j] = '.';
			}
		}
		if (flag) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (mapp1[i][j] == '*') {
						ans[i][j] = '*';
						//cout << "text:" << i << " " << j << endl;
					}
		}
	//	cout <<"text:"<< flag << endl;
		for (int i = 0; i < n; i++) {
			printf("%s\n", ans[i]);
		}
	}
    return 0;
}

