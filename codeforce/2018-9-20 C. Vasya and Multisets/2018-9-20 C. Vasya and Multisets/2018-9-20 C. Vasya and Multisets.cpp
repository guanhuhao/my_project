// 2018-9-20 C. Vasya and Multisets.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int check[110];
int a[110];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check[a[i]]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (check[a[i]] == 1) cnt++;
	int flag = 0;
	for (int i = 0; i < n; i++)
		if (check[a[i]] >= 3)flag = 1;
	if (cnt % 2 == 0 || flag == 1) {
		cout << "YES" << endl;
		if (cnt % 2 == 0) {
			int cnta = 0;
			for (int i = 0; i < n; i++) {
				if (cnta < cnt / 2 && check[a[i]] == 1) {
					cout << "A";
					cnta++;
				}
				else cout << "B";
			}
			cout << endl;
		}
		else {
			int cnta = 0;
			for (int i = 0; i < n; i++) {
				if (check[a[i]] >= 3 && flag) {
					flag = 0;
					cout << "A";
					continue;
				}
				if (cnta < cnt / 2 && check[a[i]] == 1) {
					cout << "A";
					cnta++;
				}
				else cout << "B";
				
			}
			cout << endl;
		}
	}
	else cout << "NO" << endl;
    return 0;
}

