// 2018-8-26 D - Period.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e6 + 10;
int nex[maxn];
void pre(string a) {
	int j = 0;
	nex[0] = -1;
	nex[1] = 0;
	for (int i = 2; i <= n; i++) {
		while (j > 0 && a[i - 1] != a[j]) j = nex[j];
		if (a[i - 1] == a[j])j++;
		nex[i] = j;
	}
	//cout << "text:";
	//for (int i = 0; i <= n; i++)cout << nex[i] << " ";
	//cout << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	int t = 0;

	while (cin >> n&&n) {
		string a;
		cin >> a;
		pre(a);
		cout << "Test case #" << ++t << endl;
		for (int i = 0; i < n; i++) {
			int len = i + 1;
			//cout << "text:" << i << " " << nex[i] << endl;
			if (len % (len-nex[len]) == 0&&len / (len - nex[len])!=1) cout << len << " " << len / (len-nex[len]) << endl;
		}
		cout << endl;
	}
    return 0;
}

