// 2018-6-1 Diverse Team.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
map<int, int> my;
int main()
{
	int k, n;
	cin >> k >> n;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		int tem;
		cin >> tem;
		if (my[tem] == 0) { my[tem] = 1; ans.push_back(i+1); }
	}
	if (n > ans.size())cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)cout << ans[i] << " ";
		cout << endl;
	}
    return 0;
}

