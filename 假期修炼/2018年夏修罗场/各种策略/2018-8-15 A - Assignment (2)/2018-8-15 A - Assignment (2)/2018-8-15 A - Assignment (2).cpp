// 2018-8-15 A - Assignment (2).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int const maxn = 1e5 + 10;
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		int i = 0, j = 0, mini = a[0], maxi = a[0];
		long long num = 0;
		long long ans = 0;
		for (; i < n; i++) {
			for (; j < n; j++) {
				//cout << "text1:" << (a[j] >= mini + k) << " " << (a[j] <= maxi-k  )<< endl;
				if (a[j] >= mini + k || a[j] <= maxi - k) break;
				if (a[j] < mini) mini = a[j];
				if (a[j] > maxi) maxi = a[j];
				num++;
			}
			//cout << "text:" << ans << " " << num << endl;
			ans += num;
			num--;
			if (a[i] == mini) {
				mini = a[i + 1];
				for (int k = i + 1; k < j; k++) mini = min(a[k], mini);
			}
			if (a[i] == maxi) {
				maxi = a[i + 1];
				for (int k = i + 1; k < j; k++) maxi = max(maxi, a[k]);
			}
			
		}
		ans += num;
		cout << ans << endl;
	}
    return 0;
}

