// 2018-8-29 A - Fire Net.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int edge[50];
void dfs(int x,int y) {

}
int main()
{
	int n;
	while (cin >> n) {
		string a[4];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dfs(i, j);
	}
    return 0;
}

