// 2018-5-21 B子串.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b) {
	return a.size() > b.size();
}
int main()
{
	int n, m;
	vector<int> my[2010];
	scanf("%d%d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
		char tem;
		scanf("%c", &tem);
		if (tem == '1') my[i].push_back(j);
		}
		getchar();
	}	

	sort(my, my + n, cmp);	

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			for (int k = 0; k < (int)my[j].size(); k++)
			{
				if (find(my[i].begin(), my[i].end(), my[j][k]) == my[i].end()) break;
				else if (k == my[j].size() - 1) {
					flag = 1;
					j = -1;
					i = n + 1;
					break;
				}
			}
		}
	}
	if (flag == 1) printf("YES\n");
	else printf("NO\n");
    return 0;
}

