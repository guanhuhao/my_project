// 2018-10-4 Yin and Yang Stones.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	while (cin >> a) {
		int cntb=0, cntw=0;
		int size = a.size();
		for (int i = 0; i < size; i++) {
			if (a[i] == 'W')cntw++;
			else cntb++;
		}
		if (cntb == cntw)cout << "1" << endl;
		else cout << "0" << endl;
    return 0;
}

