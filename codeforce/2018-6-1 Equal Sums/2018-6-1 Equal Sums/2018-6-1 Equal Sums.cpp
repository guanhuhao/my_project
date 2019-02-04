// 2018-6-1 Equal Sums.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#define ll long long
const int maxn = (int)2e5 + 10;
using namespace std;
map<ll, pair<int, int>> my;
int main()
{
	int n;
	ios::sync_with_stdio(false);
	int flag = 0;
	int ans1 = 0, ans2 = 0, ans3 = 0,ans4=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem[maxn];
		int num;
		ll sum=0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> tem[j];
			sum = sum + tem[j];
		}
		if (flag == 1) continue;
		set<int> fin;
		for (int j = 0; j < num; j++) {
			if (fin.find(tem[j])!=fin.end()) continue;
			if (my.find(sum - tem[j]) == my.end()) {
				pair<int, int> a(i + 1, j + 1);
				my[sum-tem[j]] = a;
			}
			else {
				ans1 = my[sum - tem[j]].first;
				ans2 = my[sum - tem[j]].second;
				ans3 = i+1;
				ans4 = j+1;
				flag = 1;
				break;
			}
			fin.insert(tem[j]);
		}

	}		
	if (flag == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			cout << ans1 << " " << ans2 << endl;
			cout << ans3 << " " << ans4 << endl;
		}
    return 0;
}

