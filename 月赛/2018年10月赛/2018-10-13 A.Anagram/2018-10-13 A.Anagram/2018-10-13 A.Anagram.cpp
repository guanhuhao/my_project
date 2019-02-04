// 2018-10-13 A.Anagram.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
map<int, int> checka, checkb;
bool cmp(char a, char b) {
	return a < b;
}
int main()
{
	string a, b;
	while (cin >> a >> b) {
		int ans = 0;
		int n = a.size();
		sort(&a[0], &a[0] + n, cmp);
		sort(&b[0], &b[0] + n, cmp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (b[j] >= a[i]) {
					ans += b[j] - a[i];
					b[j] = 0;
					a[i] = 0;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) continue;
			for (int j = 0; j < n; j++) {
				if (b[j] == 0) continue;
				ans += (b[j] - a[i] + 26) % 26;
				a[i] = 0;
				b[j] = 0;
				break;
			}
		}
		cout << ans << endl;
	}
    return 0;
}

