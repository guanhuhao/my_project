// 2018-9-17 C. Array Product(改).cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,a[maxn];
int cntf = 0;
int maxi=-1;
int vis[maxn];
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	memset(vis, 0, sizeof(vis));
	vector<int> pos0;
	vector<int> num;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			cntf++;
			if (maxi == -1 || a[maxi] > a[i]) maxi = i;
		}
		if (a[i] == 0) pos0.push_back(i);
		else num.push_back(i);
	}
	if (cntf % 2 == 1) {
		cout << "2 " << maxi << endl;
		vis[maxi] = 1;
		if(maxi==1)
			for (int i = 3; i <= n; i++) {
				if (vis[i] == 1) continue;
				cout << "1 " << i << " " << 2 << endl;
			}
		else 
			for (int i = 2; i <= n; i++) {
				if (vis[i] == 1) continue;
				cout << "1 " << i << " " << 1 << endl;
			}
	}
	else {
		for (int i = 1; i < pos0.size(); i++) cout << "1 " << pos0[i] << " " << pos0[0] << endl;
		if (pos0.size() >= 1&&!num.empty()) cout << "2 " << pos0[0] << endl;
		for (int i = 1; i < num.size(); i++) cout << "1 " << num[i] << " " << num[0] << endl;
	}
    return 0;
}

