// 2018-6-11 A Blend of Springtime.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	int flag = 0;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '.'||i+2>=a.size()) continue;
		if (a[i] + a[i + 1] + a[i + 2] == 'A' + 'B' + 'C'&&(a[i]=='B'||a[i+1]=='B'||a[i+2]=='B')&& (a[i] == 'A' || a[i + 1] == 'A' || a[i + 2] == 'A')) {
			flag = 1;
			break;
		}
	}
	flag == 0 ? cout << "No" << endl : cout << "Yes" << endl;
    return 0;
}

