// 2018-7-24 I - Bag Problem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long item[45];
ll ans;
int n;
ll  cap, maxi;
bool cmp(ll a, ll b) {
	return a < b;
}
void dfs(int s,int c,long long v) {
	if (s >= n || c <=0 || v + item[s] > maxi||v==maxi) return;
	ans = max(ans, v + item[s]);
	dfs(s + 1, c - 1, v + item[s]);
	dfs(s + 1, c, v);
}
int main()
{
	while (cin >> cap >> maxi) {
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> item[i];
		//for (int i = 0; i < n; i++) item[i] = i;
		sort(item, item + n,cmp);
		long long sum = 0;
		//for (int i = 0; i < cap; i++) sum += item[n - 1 - i];
		//if (sum <= maxi) ans = sum;
		 dfs(0, cap, 0);
		cout << ans << endl;
	}
    return 0;
}

