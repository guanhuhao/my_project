// 2018-8-10 A - 敌兵布阵.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
struct Tree {
	int l, r, v;
}tree[200050];
int built(int l, int r,int k) {
	int mid = (l + r) / 2;
	tree[k].l = l;
	tree[k].r = r;
	if (l == r) {
		cin >> tree[k].v;
		return tree[k].v;
	}
	built(l, mid, 2 * k);
	built(mid+1, r, 2 * k + 1);
	tree[k].v = tree[2 * k].v + tree[2 * k + 1].v;
	return tree[k].v;
}
int change(int pos, int value,int k) {
	if (tree[k].l == tree[k].r&&tree[k].l == pos) {
		tree[k].v += value;
		return tree[k].v;
	}
	int mid = (tree[k].l + tree[k].r) / 2;
	if (mid >= pos) change(pos, value, 2 * k);
	else change(pos, value, 2 * k + 1);
	tree[k].v = tree[2 * k].v + tree[2 * k + 1].v;
	//cout <<"text:"<<k<<" "<< tree[k].l <<" "<< tree[k].r <<" "<< tree[k].v << endl;
	return tree[k].v;
}
int ask(int l, int r, int k) {
	int ans = 0;
	if (tree[k].l > r || tree[k].r < l) return 0;
	if (l <= tree[k].l&&r >= tree[k].r) return tree[k].v;
	return ask(l, r, 2 * k) + ask(l, r, 2 * k + 1);
}
int main()
{
	int t;
	
	scanf("%d", &t);
	for (int T = 1; T <= t; T++) {
		int n;
		scanf("%d",&n);
		built(1, n, 1);
		printf("Case %d:\n", T);
		string com;
		char a[50];
		while (scanf("%s",a)) {
			com = a;
			if (com == "End") break;
			int tem1, tem2;
			scanf("%d%d", &tem1, &tem2);
			if (com == "Add" ) change(tem1, tem2, 1);
			if (com == "Sub")change(tem1, -tem2, 1);
			if (com == "Query")printf("%d\n", ask(tem1, tem2, 1));
		}

	}
    return 0;
}

