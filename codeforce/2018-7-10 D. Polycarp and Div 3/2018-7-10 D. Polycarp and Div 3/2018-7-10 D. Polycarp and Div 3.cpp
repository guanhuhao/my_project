// 2018-7-10 D. Polycarp and Div 3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int main()
{
	string a;
	int in[maxn] = {0};
	cin >> a;
	int ans = 0;
	int size = a.size();
	for (int i = 0; i < size; i++) in[i] = (a[i] - '0') % 3;
	for (int i = 0; i < size; i++) {
		if (in[i] == 0) ans++;
		else if (i + 1 < size&&in[i] + in[i + 1] == 3) { ans++; i++; }
		else if (i + 2 < size&&in[i] == in[i + 1] && in[i + 1]== in[i + 2]) { ans++; i += 2; }
	}
	cout << ans<<endl;
    return 0;
}

