// 2018-8-11 C - Just a Hook.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
struct Tree {
	int l, r, v, f;
}tree[maxn*4];
void built(int l, int r, int k) {
	int mid = (l + r) / 2;
	tree[k].l = l;
	tree[k].r = r;
	tree[k].f = 0;
	if (l == r) {
		tree[k].v = 1;
		return;
	}	
	built(l, mid, 2 * k);
	built(mid+1, r, 2 * k + 1);
	tree[k].v = tree[2 * k].v + tree[2 * k + 1].v;
}
void down(int k) {
	if (tree[k].f == 0) return;
	tree[2 * k].f = tree[k].f;
	tree[2 * k + 1].f = tree[k].f;
	tree[2 * k].v = tree[k].f*(tree[2 * k].r - tree[2 * k].l + 1);
	tree[2 * k + 1].v = tree[k].f*(tree[2 * k + 1].r - tree[2 * k + 1].l + 1);
	tree[k].f = 0;
}
void change(int l, int r, int value,int k) {
	if (tree[k].l > r || tree[k].r < l) return;
	if (tree[k].l >= l&&tree[k].r <= r) {
		tree[k].f = value;
		tree[k].v = value*(tree[k].r - tree[k].l+1);
		return;
	}
	//cout << "text:" <<k<<" "<< tree[k].l << " " << tree[k].r <<" "<<tree[2*k].v<<" "<<tree[2*k+1].v<< endl;
	down(k);

	change(l, r, value, 2 * k);
	change(l, r, value, 2 * k + 1);	
	tree[k].v = tree[2 * k].v + tree[2 * k + 1].v;
	//cout << "text:" <<k<<" "<< tree[k].l << " " << tree[k].r <<" "<<tree[2*k].v<<" "<<tree[2*k+1].v<< endl;
}
int ask(int l, int r, int k) {
	int mid = (l + r) / 2;
	if (tree[k].l > r || tree[k].r < l) return 0;
	if (tree[k].l >= l&&tree[k].r <= r) return tree[k].v;
	down(k);
	ask(l, r, 2 * k);
	ask(l, r, 2 * k + 1);
	return tree[k].v;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; T++) {
		int n,num;
		scanf("%d%d", &n,&num);
		built(1, n, 1);
		for (int i = 0; i < num; i++) {
			int tem1, tem2, tem3;
			scanf("%d%d%d", &tem1, &tem2, &tem3);
			change(tem1, tem2, tem3, 1);	
		}

		printf("Case %d: The total value of the hook is %d.\n", T, ask(1, n, 1));
	}
    return 0;
}

