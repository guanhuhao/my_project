// neuoj 164 VIJOS-P103并查集.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int _list[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int m, n, p;
	for (int i = 0; i < maxn; i++) _list[i] = i;
	cin >> n >> m >> p;
	for (int i = 0; i < m; i++)
	{
		int f, s;
		scanf("%d%d", &f, &s);
		_list[s] = f;
	}
	for (int i=0; i < p; i++)
	{
		int a, b;
		cin >> a >> b;
		while (_list[a] != a)	a = _list[a];
		while (_list[b] != b)   b = _list[b];

		if (_list[a] != _list[b]) printf("No\n");
		else printf("Yes\n");
	}
    return 0;
}

