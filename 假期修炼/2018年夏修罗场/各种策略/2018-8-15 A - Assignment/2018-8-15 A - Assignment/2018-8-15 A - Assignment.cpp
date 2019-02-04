// 2018-8-15 A - Assignment.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 10;
int a[maxn];
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		int rec1 = 0, rec2 = 0;
		if (a[0] > a[1]) rec1 = 1, rec2 = 0;

		int recmin = 0, recmax = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] >= a[recmin] + k || a[i] <= a[recmax] - k) break;
			if (a[i] <= a[recmin]) recmin = i;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] >= a[recmin] + k||a[i]<=a[recmax]-k) break;
			if (a[recmax] <= a[i]) recmax = i;
		}
		cout << "text:" << recmax << " " << recmin << endl;
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			int mini = min(recmin, recmax);
			int maxi = max(recmin, recmax);
			//cout <<"text："<< mini << endl;
			if (i <= mini) {
				ans += maxi - i + 1;
				//cout << "text:" << ans << endl;
				continue;
			}
			if (a[mini] > a[maxi]) {
				recmax = mini + 1;
				for (int j = mini + 1; j < n; j++) {
					if (a[j] >= a[recmin] + k || a[i] <= a[recmax] - k) break;
					if (a[j] >= a[recmax]) recmax = j;
				}
			}
			else {
				recmin = mini + 1;
				for (int j = mini + 1; j < n; j++) {
					if (a[j] >= a[recmin] + k || a[i] <= a[recmax] - k) break;
					if (a[j] <= a[recmin]) recmin = j;
				}
			}
			//cout << "text:" << i << endl;
		}
		cout << ans << endl;
	}
}