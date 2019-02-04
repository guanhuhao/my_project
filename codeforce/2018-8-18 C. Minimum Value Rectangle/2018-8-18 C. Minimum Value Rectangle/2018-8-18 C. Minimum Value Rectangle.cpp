// 2018-8-18 C. Minimum Value Rectangle.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
//vector<int> v;
int cnt[maxn];
int main()
{
	//ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	while (t--) {
		double ans=1e9+7;
		int k = 0;
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d",& n);
		for (int i = 0; i < n; i++) {
			int tem;
			scanf("%d",& tem);
			a[tem]++;
			if (a[tem] == 2) cnt[k++]=tem;
		}
		sort(cnt, cnt+k);	
		int rec1, rec2;		
		int flag = 0;
		for (int i = 0; i < maxn; i++) {
			if (a[i] >= 4) {
				flag = 1;
				rec1 = rec2 = i;
			}
		}
		if (flag == 0) {
			for (int i = 0; i < k - 1; i++) {
				if (ans > (double)cnt[i + 1] / (double)cnt[i]) {
					rec1 = cnt[i + 1];
					rec2 = cnt[i];
					ans = (double)cnt[i + 1] / (double)cnt[i];
				}
			}
		}

		printf("%d %d %d %d\n", rec1, rec1, rec2, rec2);
	}
    return 0;
}

