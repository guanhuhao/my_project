// 2018-7-9 B. Delete from the Left.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int same = 0;
	int mini=min(a.size(),b.size());
	for (int i = 1; i <= mini; i++) {
		if (a[a.size() - i] != b[b.size() - i]) break;
		same++;
	}
	cout << a.size() + b.size() - 2 * same << endl;
    return 0;
}

