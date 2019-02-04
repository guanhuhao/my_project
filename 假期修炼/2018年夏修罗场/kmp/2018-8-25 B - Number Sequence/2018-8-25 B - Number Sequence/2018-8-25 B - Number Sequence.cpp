// 2018-8-25 B - Number Sequence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 10];
int b[100000 + 10];
int nex[100000 + 10];	
int n, m;
void pre(int a[]) {
	int j = 0;
	nex[1] = 0;
	for (int i = 2; i <= m; i++) {
		while (j > 0 && a[j] != a[i-1]) j = nex[j];
		if (a[j] == a[i-1])j++;
		nex[i] = j;
	}
}
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	while (t--) {
		int ans = -1;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)scanf("%d",& a[i]);
		for (int i = 0; i < m; i++) scanf("%d",&b[i]);
		pre(b);
		int j = 0;
		for (int i = 0; i < n; i++) {
			while (j > 0 && a[i] != b[j])	j = nex[j];
			if (a[i] == b[j]) j++;
			if (j == m) {	
				//cout << "text:"<<i << endl;
				ans = i - m+2;
				i = n;
				break;
			}
		}
		printf("%d\n", ans);
	}

    return 0;
}

