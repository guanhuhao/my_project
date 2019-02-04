// 2018-8-1 C - Stall Reservations.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int a[50010];
queue<int> que;

int main()
{
	memset(a, 0, sizeof(a));
	int n;
	int ans=-1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;	
		cin >> s >> e;		
		for (int j = 1; j <= 50000; j++) {
			if (a[j] < s) {
				a[j] = e;
				ans = max(j,ans);
				que.push(j);
				break;
			}
		}
	}

	while (!que.empty()) {
		cout << que.front() << endl;
		que.pop();
	}
    return 0;
}

