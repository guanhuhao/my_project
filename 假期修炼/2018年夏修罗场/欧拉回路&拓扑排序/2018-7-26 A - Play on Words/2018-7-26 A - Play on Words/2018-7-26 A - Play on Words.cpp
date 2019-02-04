// 2018-7-26 A - Play on Words.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
pair<int, int> arb[26];
int fat[26];
int vis[26];
int findf(int x) {
	if (fat[x] == x) return x;
	else {
		fat[x] = findf(fat[x]);
		return fat[x];
	}
}
void unionnode(int a, int b) {
	int x = findf(a), y = findf(b);
	if (x != y) fat[x] = y;
}
int main()
{
	int t;
	cin >> t;
	ios::sync_with_stdio(false);
	while (t--) {
		int n;
		cin >> n;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 26; i++) arb[i].first = arb[i].second = 0;
		for (int i = 0; i < 26; i++) fat[i] = i;
		for (int i = 0; i < n; i++) {
			string tem;
			cin >> tem;
			int a = tem[0] - 'a', b = tem[tem.size() - 1] - 'a';
			arb[a].first++;
			arb[b].second++;
			vis[a] = vis[b] = 1;
			unionnode(a, b);
		}
		int chu = 0,ru=0,ans=0;
		for(int i=0;i<26;i++){
			if (arb[i].first != arb[i].second) {
				ans++;
				if (arb[i].first - arb[i].second == 1) chu++;
				else if (arb[i].second - arb[i].first == 1) ru++;
			}
		}
		int flag = 0;
		for (int i = 0; i < 26; i++) findf(i);
		for (int i = 0; i < 26; i++)
			if (vis[i] && fat[i] == i) flag++;
		if (flag > 1)cout << "The door cannot be opened.\n";
		else if (ans == 0 || ( ans==2&&chu == 1&&ru == 1)) cout << "Ordering is possible.\n";
		else cout<< "The door cannot be opened.\n";

	}
    return 0;
}

