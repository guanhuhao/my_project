// 2018-8-18 C - The Triangle Game.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int ans = 0;
struct triangle {
	int a, b, c;
}a[7];
int vis[7];
void dfs(int n,int s,int v,int tem) {
	if (n == 5) {
		//cout << "text:" << s << " " << tem << endl;;
		if(s==tem) ans = max(ans, v);
		return;
	}
	for (int i = 0; i < 6; i++) {
		if (vis[i] == 1) continue;
		vis[i] = 1;
		if (a[i].a == s) dfs(n + 1, a[i].b, v + a[i].c, tem);
		if (a[i].b == s) dfs(n + 1, a[i].c, v + a[i].a, tem);
		if (a[i].c == s) dfs(n + 1, a[i].a, v + a[i].b, tem);
		vis[i] = 0;
	}

}
int main()
{
	while (1) {
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for (int i = 0; i < 6; i++) cin >> a[i].a >> a[i].b >> a[i].c;
		vis[0] = 1;
		dfs(0, a[0].a, a[0].b, a[0].c);
		dfs(0, a[0].b, a[0].c, a[0].a);
		dfs(0, a[0].c, a[0].a, a[0].b);
		if(ans)cout << ans << endl;
		else cout << "none" << endl;
		string tem;
		cin >> tem;
		if (tem == "$") break;
	}
    return 0;
}

