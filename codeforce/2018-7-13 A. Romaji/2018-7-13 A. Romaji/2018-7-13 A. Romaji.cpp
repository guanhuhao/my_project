// 2018-7-13 A. Romaji.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
char yuan[5] = { 'a','e','i','o','u' };
int main()
{
	string in;
	int ans = 0;
	cin >> in;
	for (int i = 0; i < in.size(); i++) {
		int flag = 0;
		for (int j = 0; j < 5; j++) {
			if (in[i] == yuan[j]||in[i]=='n') flag = 1;
		}
		if (flag == 0) {
			if (in[i + 1] != 'a'&&in[i + 1] != 'e'&&in[i + 1] != 'o'&&in[i + 1] != 'u'&&in[i + 1] != 'i') ans = 1;
		}
	}
	ans ? cout << "NO" << endl : cout << "YES" << endl;
    return 0;
}

