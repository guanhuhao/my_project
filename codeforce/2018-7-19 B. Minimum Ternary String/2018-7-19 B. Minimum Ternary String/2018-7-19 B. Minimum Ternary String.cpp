// 2018-7-19 B. Minimum Ternary String.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	string s1;
	string s2;
	string s3;
	cin >> a;
	int size = a.size(); 
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (!flag&&a[i]!='1') {
			if (a[i] == '0') s1.push_back('0');
			else {
				flag = 1;
				s3.push_back('2');
			}
		}
		else if (a[i] != '1') s3.push_back(a[i]);
		else s2.push_back('1');
	}

	cout << s1 << s2 << s3<<endl;
    return 0;
}
