// 2018-9-17 B. Vitamins.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int mini[7];
	for (int i = 0; i < 7; i++) mini[i] = 10000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		string a;
		cin >> tem >> a;
		if (a.size() == 1) mini[a[0] - 'A'] = min(mini[a[0] - 'A'], tem);
		else if(a.size()==2){
			if (a[0] != 'C'&&a[1] != 'C') mini[3] = min(mini[3], tem);
			else if (a[0] != 'B'&&a[1] != 'B') mini[4] = min(mini[4], tem);
			else mini[5] = min(mini[5], tem);
		}
		else mini[6] = min(mini[6], tem);
	}
	int ans;
	ans = mini[6];
	//for (int i = 0; i < 7; i++) cout << i << " " << mini[i] << endl;
	ans = min(ans, mini[0] + mini[1] + mini[2]);
	ans = min(ans, mini[0] + mini[5]);
	ans = min(ans, mini[1] + mini[4]);
	ans = min(ans, mini[2] + mini[3]);
	ans = min(ans, mini[3] + mini[4]);
	ans = min(ans, mini[3] + mini[5]);
	ans = min(ans, mini[4] + mini[5]);
	if (ans == 10000000) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}

