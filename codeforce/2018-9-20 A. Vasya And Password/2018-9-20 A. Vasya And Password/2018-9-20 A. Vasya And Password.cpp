// 2018-9-20 A. Vasya And Password.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		int flag1, flag2, flag3;
		int cnt1, cnt2, cnt3;
		cnt1 = cnt2 = cnt3 = 0;
		flag1 = flag2 = flag3 = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0'&&a[i] <= '9') {
				flag1=1;
				cnt1++;
			}
			if (a[i] >= 'a'&&a[i] <= 'z') {
				flag2=1;
				cnt2++;
			}
			if (a[i] >= 'A'&&a[i] <= 'Z') {
				flag3=1;
				cnt3++;
			}
		}
			
		if (flag1 + flag2 + flag3 == 3) ;
		else if (flag1 + flag2 + flag3 == 2) {
			if (flag1 == 0) {
				if (cnt2 >= 2) {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] <= 'z'&&a[i] >= 'a') {
							a[i] = '1';
							break;
						}
					}
				}
				else {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] <= 'Z'&&a[i] >= 'A') {
							a[i] = '1';
							break;
						}
					}
				}
			}
			if (flag2 == 0) {
				if (cnt1 >= 2) {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] >= '0'&&a[i] <= '9') {
							a[i] = 'a';
							break;
						}
					}
				}
				else {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] <= 'Z'&&a[i] >= 'A') {
							a[i] = 'a';
							break;
						}
					}
				}
			}
			if (flag3 == 0) {
				if (cnt1 >= 2) {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] >= '0'&&a[i] <= '9') {
							a[i] = 'A';
							break;
						}
					}
				}
				else {
					for (int i = 0; i < a.size(); i++) {
						if (a[i] >= 'a'&&a[i] <= 'z') {
							a[i] = 'A';
							break;
						}
					}
				}
			}	
		}
		else {
			if (flag1 == 1) {
				a[0] = 'a';
				a[1] = 'A';
			}
			if (flag2 == 1) {
				a[0] = '1';
				a[1] = 'A';
			}
			if (flag3 == 1) {
				a[0] = '1';
				a[1] = 'a';
			}
		}
		cout << a << endl;
	}
    return 0;
}

