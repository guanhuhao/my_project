// 2018-8-17 D. Array Restoration.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int vis[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	int flag = 0;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) continue;
		if (vis[a[i]] == 1) {
			flag = 1;
			break;
		}
		vis[a[i]] = 1;
		int tem = i;
		int recl = i, recr = i;
		
		while (i+1<n&&(a[i + 1] == a[tem]||a[i+1]==0)) {
			cout<<"text:"<<
			for (int j = recl; j <= recr; j++) a[j] = a[tem];
			while (i+1<n&&a[i + 1] == a[tem])i++;
			if (i < n&&a[i] == 0) {
				recl = i;
				for (; i < n&&a[i + 1] == 0; i++);
				recr = i - 1;
			}
		}
	}	//for (int i = 0; i < n; i++) cout << a[i] << " ";
	int flag2 = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == q) {
			flag2 = 0;
			break;
		}
	}
	if (flag2 == 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				a[i] = q;
				flag2 = 0;
				break;
			}
		}
		if (flag2 == 1) flag = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!a[i]) continue;
		int recl = i - 1;
		while (i + 1 < n&&a[i + 1] == 0)i++;
		int recr = i;
		for (int j = recl; j <= recr; j++) a[j] = a[recl];
	}
	if (flag == 1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) cout << a[i] << " ";

		cout << endl;
	}
    return 0;
}

