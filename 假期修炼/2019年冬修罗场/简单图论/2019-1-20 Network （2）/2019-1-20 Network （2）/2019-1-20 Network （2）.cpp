// 2019-1-20 Network （2）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int fat[maxn];
int fat2[maxn];
int findf(int x) {
	return x == fat[x] ? x : fat[x] = findf(fat[x]);
}
int findf2(int x) {
	return x == fat2[x] ? x : fat2[x] = findf2(fat2[x]);
}
void init() {
	for (int i = 0; i < maxn; i++) fat[i] = i;
}
int main()
{
	int T = 0;
	while (~scanf("%d%d",&n,&m)&&n) {
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			int aa = findf(a),
				bb = findf(b);
			if (aa != bb) fat[aa] = bb;
			else {
				aa = findf2(a);
				bb = findf2(b);
				if (aa != bb) fat2[aa] = bb;
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a,b,
		}
		
	}
    return 0;
}

