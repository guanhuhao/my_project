// 2018-8-3 B. Segment Occurrences.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, l, q;
	int next[105];
	next[0]=1;
	string a, b;
	cin >> n >> l >> q;
	cin >> a >> b;
	for (int i = 0; i < q; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		int ans = 0;
		for (int k = tem1 - 1;k <= tem2 - l; k++) {
			int j;

			for (j = 0; j < l; j++) {
				//cout << a[i + j] << " " << b[j] << endl;
				if (a[k + j] != b[j])break;
			}
			if (j == l) ans++;
		}
		cout << ans << endl;
		auto l = &a[tem2];
		while (l=find(l, &a[tem2], b) != &a[tem2]) {
			ans++;
		}
	}
	return 0;
}

