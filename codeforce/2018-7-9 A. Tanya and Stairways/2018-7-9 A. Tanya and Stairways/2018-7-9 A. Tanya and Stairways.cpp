// 2018-7-9 A. Tanya and Stairways.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[1010];
	cin >> n;
	vector<int> v;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ans++;
			if (i != 0) v.push_back(count);	
			count = 0;
		}
		count++;
	}
	v.push_back(count);
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
    return 0;
}

