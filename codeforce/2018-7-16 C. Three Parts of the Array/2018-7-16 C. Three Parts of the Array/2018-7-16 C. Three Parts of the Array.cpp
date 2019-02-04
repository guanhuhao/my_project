// 2018-7-16 C. Three Parts of the Array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn] = {0};
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i]+= a[i-1];
	}
	//for (int i = 0; i <= n; i++) cout << a[i] << " ";
	//cout << endl;
	int l=1, r=n-1;
	long long ans = 0;
	while (l <= r) {	
		//cout << a[l]  << "  " << a[n] - a[r] << endl;
		if ( a[l]== a[n] - a[r]) ans = a[l];
		if ( a[l] > (a[n] - a[r])) r--;
		else l++;

	}
	cout << ans<<endl;
    return 0;
}

