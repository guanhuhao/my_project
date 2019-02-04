// 2018-9-23 C. Vasya and Golden Ticket.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[110];
	memset(a, 0, sizeof(a));
	cin >> n;
	for(int i=1;i<=n;i++)	scanf("%1d", &a[i]);
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	for (int i = 1; i <= n-1; i++) {
		int sum = a[i];
		int flag = 0;
		int l = i,r;
		for (r = i + 1; r <= n; r++) {
			if (a[r] - a[l] == sum) {
				l = r;
				flag = 1;
			}
			if (a[r] - a[l] > sum) break;
		}
		if (flag == 1 && a[n] - a[l] == 0) l = n;
	//	cout << "text:" << l << " " << a[l] << endl;
		if (l == n) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}

