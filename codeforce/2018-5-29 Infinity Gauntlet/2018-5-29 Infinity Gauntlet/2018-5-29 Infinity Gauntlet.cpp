// 2018-5-29 Infinity Gauntlet.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int a[7];
string b[7] = { "Power","Time","Space","Soul","Reality","Mind" };
int main()
{
	int T;
	ios::sync_with_stdio(false);
	scanf("%d", &T);
	char tem[10];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < T; i++) {
		scanf("%s", tem);
		if (strcmp(tem , "purple")==0) a[0] = 1;
		else if (strcmp(tem , "green")==0)a[1] = 1;
		else if (strcmp(tem , "blue")==0)a[2] = 1;
		else if (strcmp(tem , "orange")==0)a[3] = 1;
		else if (strcmp(tem , "red")==0)a[4] = 1;
		else if (strcmp(tem , "yellow")==0)a[5] = 1;
	}
	cout << 6 - T << endl;
	for (int i = 0; i < 6; i++) {
		if (a[i] == 0 ) cout << b[i] << endl;
	}
	return 0;
}