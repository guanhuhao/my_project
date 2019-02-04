// 2018-8-11 M - Stars.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 320000 + 10;
struct Tree {
	int l, r,v;
}tree[maxn * 8];
void built(int l,int r,int k) {
	int mid = (l + r) / 2;
	tree[k].l = l;
	tree[k].r = r;
	tree[k].v = 0;	
	if (l == r)return;
	built(l, mid, 2 * k);
	built(mid + 1,r, 2 * k + 1);
}
void change(int p,int k) {
	if (tree[k].l == tree[k].r&&tree[k].l == p) {
		tree[k].v+=1;
		return;
		//cout << "text:"<<tree[k].l <<" "<<tree[k].v<< endl;
	}
	if (tree[k].r<p || tree[k].l>p) return;
	int mid = (tree[k].l + tree[k].r) / 2;
	//cout << "text:" << k << endl;
	if (p <= mid) change(p, 2 * k);
	else change(p, 2 * k + 1);
	tree[k].v = tree[2 * k].v + tree[2 * k + 1].v;
	//cout << "text:"<<tree[k].v << endl;
}
int ask(int l, int r, int k) {	
	//cout <<"text"<< tree[k].l << " " << tree[k].r <<" "<<tree[k].v<< endl;
	if (tree[k].l >= l&&tree[k].r <= r) return tree[k].v;
	if (tree[k].l > r || tree[k].r < l) return 0;
	return ask(l, r, 2 * k)+ask(l, r, 2 * k + 1);
}
int ans[15005];
int main()
{
	int n;
	char a[20];
	printf("%s", a);
	memset(ans, 0, sizeof(ans));
	while (scanf("%d", &n) != EOF) {

		built(0, maxn, 1);
		for (int i = 0; i < n; i++) {
			int tem1, tem2;
			scanf("%d%d", &tem1, &tem2);
			ans[ask(0, tem1, 1)]++;
			//printf("hahha\n");
			change(tem1, 1);
		}
		for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
	}
    return 0;
}

