// 2018-6-9 saruman‘s army.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, r;
	int x[10000];
	while(cin>>r>>n){
		int ans = 0;
		memset(x, 0, sizeof(x));
		if (r == n&&r == -1) break;
		for (int i = 0; i < n; i++) {
			int tem;
			cin >> tem;
			x[tem] = 1;
		}
		int p = 0;
		while (p <= 1000) {
			while (!x[p] && p <= 1000) p++;
			//cout << p<<endl;
			if (p > 1000) break;
			p += r;		
			ans++;
			if (p > 1000) break;	
			while (!x[p])p--;	
			p += r;			
			x[p] = 0;
		}
		cout << ans << endl;
	}
    return 0;
}

