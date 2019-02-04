// 2019-1-17 Square Destroyer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int edge[65];
int ans;
int text;
bool check(int n,int &flag) {
	text++;
	flag = 0;
	int ld = n,
		rd = n + 1,
		d = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 1 + rd] + edge[d*i + j + 1 + ld] + edge[d*(i + 1) + j + 1]) continue;
			flag = d*(i + 1) + j + 1;
			return false;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 1 + 1] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 1 + 1 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 1 + 1 + rd] +
				edge[d*(i + 2) + j + 1] + edge[d*(i + 2) + j + 1 + 1]
				) continue;
			flag = d*(i + 2) + j + 1 + 1;
			return false;
		}
	}
	for(int i=0;i<n-2;i++)
		for (int j = 0; j < n - 2; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 2]  + edge[d*i + j + 3] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 3 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 3 + rd] +
				edge[d*(i + 2) + j + 1 + ld] + edge[d*(i + 2) + j + 3 + rd] +
				edge[d*(i + 3) + j + 1] + edge[d*(i + 3) + j + 2] + edge[d*(i + 3) + j + 3]
				)continue;
			flag = d*(i + 3) + j + 3;
			return false;
		}
	for(int i=0;i<n-3;i++)
		for (int j = 0; j < n - 3; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 2] + edge[d*i + j + 3] + edge[d*i + j + 4] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 4 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 4 + rd] +
				edge[d*(i + 2) + j + 1 + ld] + edge[d*(i + 2) + j + 4 + rd] +
				edge[d*(i + 3) + j + 1 + ld] + edge[d*(i * 3) + j + 4 + rd] +
				edge[d*(i + 4) + j + 1] + edge[d*(i + 4) + j + 2] + edge[d*(i + 4) + j + 3] + edge[d*(i + 4) + j + 4]
				)continue;
			flag = d*(i + 4) + j + 4;
			return false;
		}
	if (n == 5) {
		int sum = 0;
		for (int i = 1; i <= 5; i++) sum = sum + edge[i] + edge[i + 55];
		for (int i = 6; i <= 50; i += 11)sum += sum + edge[i] + edge[i + 5];
		if (!sum) return false;
	}
	return true;
}
bool check2(int n,int tar) {
	int ld = n,
		rd = n + 1,
		d = 2 * n + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 1 + rd] + edge[d*i + j + 1 + ld] + edge[d*(i + 1) + j + 1]) continue;
			if (d*i + j + 1 == tar || d*i + j + 1 + rd == tar || d*i + j + 1 + ld == tar || d*(i + 1) + j + 1 == tar) return true;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 1 + 1] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 1 + 1 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 1 + 1 + rd] +
				edge[d*(i + 2) + j + 1] + edge[d*(i + 2) + j + 1 + 1]
				) continue;

			if (d*i + j + 1 == tar || d*i + j + 1 + 1 == tar || d*i + j + 1 + ld == tar || d*i + j + 1 + 1 + rd == tar||
				d*(i + 1) + j + 1 + ld == tar || d*(i + 1) + j + 1 + 1 + rd == tar || d*(i + 2) + j + 1 == tar || d*(i + 2) + j + 1 + 1 == tar) return true;
		}
	}
	for (int i = 0; i<n - 2; i++)
		for (int j = 0; j < n - 2; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 2] + edge[d*i + j + 3] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 3 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 3 + rd] +
				edge[d*(i + 2) + j + 1 + ld] + edge[d*(i + 2) + j + 3 + rd] +
				edge[d*(i + 3) + j + 1] + edge[d*(i + 3) + j + 2] + edge[d*(i + 3) + j + 3]
				)continue;
			if(d*i + j + 1==tar|| d*i + j + 2==tar|| d*i + j + 3==tar|| d*i + j + 1 + ld|| d*i + j + 3 + rd||
				d*(i + 1) + j + 1 + ld|| d*(i + 1) + j + 3 + rd|| d*(i + 2) + j + 1 + ld|| d*(i + 2) + j + 3 + rd||
				d*(i + 3) + j + 1|| d*(i + 3) + j + 2|| d*(i + 3) + j + 3
				)
			return true;
		}
	for (int i = 0; i<n - 3; i++)
		for (int j = 0; j < n - 3; j++) {
			if (edge[d*i + j + 1] + edge[d*i + j + 2] + edge[d*i + j + 3] + edge[d*i + j + 4] +
				edge[d*i + j + 1 + ld] + edge[d*i + j + 4 + rd] +
				edge[d*(i + 1) + j + 1 + ld] + edge[d*(i + 1) + j + 4 + rd] +
				edge[d*(i + 2) + j + 1 + ld] + edge[d*(i + 2) + j + 4 + rd] +
				edge[d*(i + 3) + j + 1 + ld] + edge[d*(i * 3) + j + 4 + rd] +
				edge[d*(i + 4) + j + 1] + edge[d*(i + 4) + j + 2] + edge[d*(i + 4) + j + 3] + edge[d*(i + 4) + j + 4]
				)continue;
			if(d*i + j + 1==tar|| d*i + j + 2|| d*i + j + 3|| d*i + j + 4|| d*i + j + 1 + ld|| d*i + j + 4 + rd||
				d*(i + 1) + j + 1 + ld|| d*(i + 1) + j + 4 + rd|| d*(i + 2) + j + 1 + ld|| d*(i + 2) + j + 4 + rd||
				d*(i + 3) + j + 1 + ld|| d*(i * 3) + j + 4 + rd|| d*(i + 4) + j + 1|| d*(i + 4) + j + 2||
				d*(i + 4) + j + 3|| d*(i + 4) + j + 4
				)
			return true;
		}
	if (n == 5) {
		int sum = 0;
		int flag = 0;
		for (int i = 1; i <= 5; i++) {
			sum = sum + edge[i] + edge[i + 55];
			if (i == tar || i + 55 == tar) flag = 1;
		}
		for (int i = 6; i <= 50; i += 11) {
			sum += sum + edge[i] + edge[i + 5];
			if (tar == i || tar == i + 5) flag = 1;
		}
		if (!sum&&flag) return true;
	}
	return false;
}
void dfs(int n,int now,int cnt) {
	if (cnt > ans ) return;
	int flag;
	if (check(n,flag)) {
		//cout << "text:" << text << " "<<cnt << endl;
		ans = min(ans, cnt);
		return;
	}
	if (now > 2 * n*(n + 1)||flag<now)return;	
	dfs(n, now + 1, cnt);
	if (!edge[now]) {
		edge[now] = 1;
		dfs(n, now + 1, cnt + 1);
		edge[now] = 0;
	}

}
int main()
{
	//freopen("in.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		text = 0;
		ans = 100;
		memset(edge, 0, sizeof(edge));
		int n,m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int tem;
			cin >> tem;
			edge[tem] = 1;
		}
		dfs(n,1,0);
		cout << ans << endl;
		//cout << text << endl;
	}
    return 0;
}

