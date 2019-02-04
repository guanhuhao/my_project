// 2018-7-14 B. Minimum Ternary String.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main()
{
	while (1) {
		string a;
		string ans;
		int in[maxn];
		cin >> a;
		int size = a.size();
		for (int i = 0; i < size; i++) in[i] = a[i] - '0';
		int i = 0;
		while (i < size) {
			int c0 = 0, c1 = 0, c2 = 0;
			while (in[i] != 2 && i < size) {
				if (in[i] == 0) c0++;
				else c1++;
				i++;
			}
			if (i<size&&in[i]==2){
				c2++;
				i++;
			}
			while (in[i] != 0 && i < size) {
				if (in[i] == 1) c1++;
				else c2++;
				i++;
			}
			for (int j = 0; j < c0; j++) ans.push_back('0');
			for (int j = 0; j < c1; j++) ans.push_back('1');
			for (int j = 0; j < c2; j++) ans.push_back('2');
		}
		cout << ans << endl;
	}
    return 0;
}

