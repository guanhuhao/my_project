// 2018-8-11 L - Ultra-QuickSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
using namespace std;
int a[500050];
long long ans = 0;
void merge_sort(int l,int r){
	int mid = (l + r) / 2;
	if (l == r) return ;
	merge_sort(l, mid);
	merge_sort(mid+1, r);
	int p1 = l, p2 = mid + 1;
	vector<int> v;
	while(p1<=mid&&p2<=r){
		if (a[p1] <= a[p2]) {
			v.push_back(a[p1++]);
		}
		else {
			v.push_back(a[p2++]);
			ans += (long long)(mid -p1+1);
			//cout << "text:" << p1 << " " << mid << " " << ans <<" "<<a[p2-1]<< endl;
		}
	}

	while (p1 <= mid) v.push_back(a[p1++]);
	while (p2 <= r) v.push_back(a[p2++]);
	for (int i = l; i <= r; i++) a[i] = v[i - l];
}
int main()
{
	int n;
	while (scanf("%d", &n)!=EOF && n) {
		ans = 0;
		for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
		merge_sort(0, n - 1);
		printf("%lld\n", ans);
	}
    return 0;
}

