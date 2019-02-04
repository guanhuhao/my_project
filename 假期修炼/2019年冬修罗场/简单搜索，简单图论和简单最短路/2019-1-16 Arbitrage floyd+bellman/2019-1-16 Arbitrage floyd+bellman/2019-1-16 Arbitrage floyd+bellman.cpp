// 2019-1-16 Arbitrage floyd+bellman.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;
map<string, int> tra;
int n,m;
double edge[35][35];
void floyd() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if(edge[j][k] < edge[j][i] * edge[i][k])
					edge[j][k] = edge[j][i] * edge[i][k];
			}
		}
	}
}
int main()
{
	int T = 1;
	while (cin >> n&&n) {
		memset(edge, 0, sizeof(edge));
		tra.clear();
		for (int i = 0; i < n; i++) edge[i][i] = 1;
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			tra[name] = i;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			string a, b;
			double value;
			cin >> a >> value >> b;
			edge[tra[a]][tra[b]] = value;
		}
	
		floyd();	/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << edge[i][j] << " ";
			cout << endl;
		}*/
		double maxi = 0;
		for (int i = 0; i < n; i++) {
			maxi = max(maxi, edge[i][i]);
			//cout << "text:" << edge[i][i] << endl;
		}
		cout << "Case " << T++ << ": ";
		if (maxi > 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}

