// 2018-8-24 C. Maximal Intersection.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int l[maxn], r[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int main()
{
	int n;
	int ans =0;
	int maxl1,maxl2,minr1,minr2;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
	maxl1 = max(l[0], l[1]);
	maxl2 = l[0] + l[1] - maxl1;
	minr1 = min(r[0], r[1]);
	minr2 = r[0] + r[1] - minr1;
	for (int i = 2; i < n; i++) {
		if (l[i] >= maxl1) {
			maxl2 = maxl1;
			maxl1 = l[i];
		}
		else maxl2 = max(maxl2, l[i]);
		if (r[i] <= minr1) {
			minr2 = minr1;
			minr1 = r[i];
		}
		else minr2 = min(minr2, r[i]);
	}
	for (int i = 0; i < n; i++) {
		int teml=maxl1, temr=minr1;
		if (l[i] == maxl1) teml = maxl2;
		if (r[i] == minr1) temr = minr2;
		//cout <<"haha"<< minr1 << " " << minr2 << endl;
		//cout << "text:" << temr << " " << teml << " "<<ans<<endl;
		ans = max(temr - teml, ans);
	}
	cout << ans << endl;
    return 0;
}

