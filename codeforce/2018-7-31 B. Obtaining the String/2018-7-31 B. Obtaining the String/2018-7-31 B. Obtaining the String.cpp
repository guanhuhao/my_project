// 2018-7-31 B. Obtaining the String.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string a, b;
	cin >> n;
	cin >> a >> b;
	char tema[55], temb[55];
	for (int i = 0; i <= n; i++) {
		tema[i] = a[i];
		temb[i] = b[i];
	}
	sort(tema, tema + n);
	sort(temb, temb + n);
	//cout << tema << endl << temb << endl;
	if (strcmp(tema, temb) != 0) {
		cout << -1 << endl; 
		return 0;
	}
	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			int j = i;
			for (; j < n; j++)
				if (a[j] == b[i])
					break;
			for (int k = j - 1; k >= i; k--) {
				ans++;
				char tem3 = a[k];
				a[k] = a[k + 1];
				a[k + 1] = tem3;
				v.push_back(k+1);
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++)cout << v[i] << " ";
	cout << endl;
    return 0;
}

