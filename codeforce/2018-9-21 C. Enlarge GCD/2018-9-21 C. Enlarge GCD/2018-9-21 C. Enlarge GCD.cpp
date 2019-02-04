// 2018-9-21 C. Enlarge GCD.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn];
map<int, int> check;
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		check.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			check[a[i]]++;
		}
		sort(a, a + n, cmp);
		//for (int i = 0; i < n; i++) cout << a[i] << " ";
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 2; j <= sqrt(a[i]); j++) {
				//cout << "text1:" << a[i] << " " << a[j] << endl;
				if (a[i] % j == 0) {
					if (check[j])
						ans = max(ans, j);
					if (check[a[i] / j]) ans = max(ans, a[i] / j);
				}
			}
		}
		//cout << "text:" << ans << endl;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			//cout << "text:" << a[i] << " " << ans<<" "<<a[] << endl;
			if (a[i] < ans || a[i] % ans != 0) cnt++;
		}
		if (check[a[0]] == n) cout << -1 << endl;
		else cout << cnt << endl;
	}
    return 0;
}

