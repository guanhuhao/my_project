// 2019-1-20 Rochambeau.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
int chd[505];
int fat[505];
int ans[505];
void init() {
	memset(chd, 0, sizeof(chd));
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < 505; i++) fat[i] = i;
}
int findf(int x) {
	if (x == fat[x]) return x;
	int t = fat[x];	
	fat[x] = findf(fat[x]);
	chd[x] += chd[t] % 3;
	return fat[x];
}
void uni(int x, int y) {
	int xx = findf(x),
		yy = findf(y);
	if (xx != yy)fat[xx] = yy;
}
int main()
{
	freopen("in.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	int n,m;
	while (cin >> n >> m) {
		init();
		int rec,cnt=0,rec2;
		for (int i = 0; i < m; i++) {
			int a, b;
			char cha;
			cin >> a >> cha >> b;
			if (cha == '>') swap(a, b);
			
			if (findf(a)!=findf(b)) {
				if (cha == '=') chd[fat[b]] = (chd[a] + chd[b]) % 3;
					else chd[fat[b]] = (chd[a] + 1 + chd[b]) % 3;
				uni(a, b);
				continue;
			}
			else {
				if (cha == '=') {
					if (chd[a] != chd[b]) {
						ans[a]++;
						ans[b]++;
						chd[fat[a]] = (chd[b] + chd[a]) % 3;
						cout << "text:" << a << " " << b<<endl;
					}
				}
				else if ((chd[a] + 1) % 3 != chd[b]) {
					ans[a]++;
					ans[b]++;
					chd[fat[b]] = (chd[b] + chd[a]+1) % 3;
					cout << "text:" << a << " " << b<<endl;
				}
				if (ans[a] == 2 || ans[b] == 2) {
					cnt++;
					rec = i + 1;
					if (ans[a] == 2) rec2 = a;
					else rec2 = b;
				}
			}
		}
		for(int i=0;i<n;i++) if(ans[i]==1)
		if (n == 1) cout << "Player 0 can be determined to be the judge after 0 lines" << endl;
		else if (cnt >= 2)cout << "Impossible" << endl;
		else if (cnt == 0) cout << "Can not determine" << endl;
		else cout << "Player " << rec2 << " can be determined to be the judge after " << rec << " lines" << endl;
	}
    return 0;
}

