// 2018-8-19 A. Doggo Recoloring.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int tem[27];
	string str;
	memset(tem, 0, sizeof(tem));
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		tem[str[i] - 'a']++;
	}  
	int flag = 0;
	for (int i = 0; i <= 26; i++) {
		if (tem[i] >= 2) flag=1;
	}
//	cout << flag << endl;
	if (flag == 1||n==1) cout << "Yes" << endl;
	else cout << "No"<<endl;
	return 0;
}

