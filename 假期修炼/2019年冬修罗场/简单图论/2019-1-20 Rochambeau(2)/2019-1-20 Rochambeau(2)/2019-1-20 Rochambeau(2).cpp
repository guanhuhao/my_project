// 2019-1-20 Rochambeau(2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int rec,rec2;
struct Q {
	int a, b,flag;
}q[2020];
int fat[510];
int chd[510];
int findf(int x) {                              //需要之后看看
	if (fat[x] == x)return x;
	int t = findf(fat[x]);	
	chd[x] = (chd[x] + chd[fat[x]]) % 3;
	return fat[x]=t;
}
/*int findf(int x) {
	if (fat[x] == x)return x;
	int t = fat[x];
	fat[x] = findf(fat[x]);
	chd[x] = (chd[x] + chd[fat[x]]) % 3;
	return fat[x];
}*/
void init() {
	for (int i = 0; i < 510; i++) fat[i] = i;
	memset(chd, 0, sizeof(chd));
}
int check(int x) {
	init();
	for (int i = 0; i < m; i++) {
		if (q[i].a == x || q[i].b == x) continue;
		if (findf(q[i].a) != findf(q[i].b)) {
			chd[fat[q[i].b]] = (chd[q[i].a] - chd[q[i].b] + q[i].flag+3) % 3;
			fat[fat[q[i].b]] = fat[q[i].a];
		}
		else {
			if (chd[q[i].b] != (chd[q[i].a] + q[i].flag)%3) {
				rec2 = max(rec2, i + 1);
				return 0;
			}
		}
	}
	rec = x;
	//cout << "text:" << x << endl;
	return 1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//std::ios::sync_with_stdio(false);
	while (~scanf("%d%d",&n,&m)) {
		rec2 = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			char tem;
			cin >> a >> tem >> b;
			if (tem == '=') q[i] = Q{ a,b,0 };
			else if (tem == '<') q[i] = Q{ a,b,1 };
			else q[i] = Q{ b,a,1 };
		}
		int cnt = 0;
	
		for (int i = 0; i < n; i++) {
			cnt += check(i);
			//cout << cnt << endl;
		}
		//cout << cnt << endl;

		if (cnt > 1) printf("Can not determine\n");
		else if (cnt == 0) printf("Impossible\n"); 
		else {
			printf("Player %d can be determined to be the judge after %d lines\n", rec, rec2);
		}
		
	}
    return 0;
}

