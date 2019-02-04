// 2018-8-10 B - I Hate It.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 20;
int maxi(int a, int b) {
	return a > b ? a : b;
}
struct Tree {
	int l, r, m;
}tree[maxn*3];
int built(int l,int r,int k){
	tree[k].l = l;
	tree[k].r = r;
	if (l == r) {
		scanf("%d", &tree[k].m);
		return tree[k].m;
	}
	int mid = (l + r) / 2;
	built(l, mid, 2 * k);
	built(mid + 1, r, 2 * k + 1);
	tree[k].m = max(tree[k * 2].m, tree[k * 2 + 1].m);
	return tree[k].m;
}
int change(int pos,int value,int k){
	int mid = (tree[k].l + tree[k].r) / 2;
	if (tree[k].l == tree[k].r&&tree[k].l == pos) {
		tree[k].m = value;
		return value;
	}	
	//cout << "text:" << k << " " << tree[k].l << " " << tree[k].r << " " << tree[k].m << endl;
	if (pos <= mid) change(pos, value, 2 * k);
	else change(pos, value, 2 * k+1);
	tree[k].m = max(tree[2 * k].m, tree[2 * k + 1].m);

	return tree[k].m;
}
int ask(int l, int r, int k) {
	int mid = (tree[k].l + tree[k].r) / 2;
	if (l <= tree[k].l&&r >= tree[k].r) return tree[k].m;
	if (l > tree[k].r || r < tree[k].l) return -1;
	return max(ask(l, r, 2 * k), ask(l, r, 2 * k + 1));
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {

		built(1,n,1);
		for (int i = 0; i < m; i++) {
			char tem[5];
			int tem1, tem2;		
			string com;
			scanf("%s%d%d", tem, &tem1,&tem2);
			com = tem;
			//printf("%s", tem);
			if (com == "U") change(tem1, tem2,1);
			else if (com == "Q") printf("%d\n",ask(tem1, tem2, 1));
		}
	}
    return 0;
}

