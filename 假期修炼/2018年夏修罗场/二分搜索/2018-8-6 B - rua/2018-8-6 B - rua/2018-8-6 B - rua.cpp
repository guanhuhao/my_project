// 2018-8-6 B - rua.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
	ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	//for (int i = 0; i < n; i++) cout << a[i] << " ";
	//cout << endl;
	int l = 0,r=a[n-1]-a[0];
	while (r - l > 1) {
		int mid = (r + l) / 2;
		int num = 1;
		int s = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] >= mid + a[s]) {
				s = i;
				num++;
			}
		}
		//cout << l<<" "<<r<<" "<<num << endl;
		if (num >= c)l = mid ;
		else r = mid-1;
	}
	int num = 1;
	int s = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] >= r + a[s]) {
			s = i;
			num++;
		}
	}
	if (num >= c) r = r;
	else r = l;
	cout << r << endl;
    return 0;
}

