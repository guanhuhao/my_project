// 2018-7-31 A - Cleaning Shifts.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
typedef pair<int,int> P;
P a[25010];
bool cmp(P a, P b) {
	return a.first < b.first;
}
int main()
{
	int n, t;	
	int ans=0;
	ios::sync_with_stdio(false);
	cin >> n >> t;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	int r = 0;
	int k = 0;
	int flag = 0;
	sort(a, a + n,cmp);
	//for (int i = 0; i < n; i++) cout << a[i].first << " " << a[i].second << endl;
	while (r < t) {
		int maxi = -1;
		while (k<n&&a[k].first <= r+1) {
			maxi = max(maxi, a[k].second);
			k++;
		}
		if (maxi <= r) {
			flag = 1;
			break;
		}
		ans++;
		//cout << maxi << endl;
		r = maxi;
	}
	cout << (flag==1 ? -1 : ans) << endl;
    return 0;
}

