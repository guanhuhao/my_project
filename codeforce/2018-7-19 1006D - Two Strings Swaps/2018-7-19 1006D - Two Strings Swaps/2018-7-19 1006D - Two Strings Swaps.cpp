// 2018-7-19 1006D - Two Strings Swaps.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string a, b;
	cin >> n >> a >> b;
	int num = n / 2;
	int ans = 0;
	for (int i = 0; i < num; i++) {
		map<char, int> m;
		m[a[i]]++; m[a[n - 1 - i]]++;
		m[b[i]]++; m[b[n - 1 - i]]++;
		//getchar();
		if (m.size() == 4) ans += 2;
		else if (m.size() == 3) ans += (1+(a[i]==a[n-1-i]));
		else if (m.size() == 2)ans += (m[a[i]]!=2);
	}
	if (n % 2 == 1 && a[num] != b[num]) ans++;
	cout << ans<<endl;
    return 0;
}

