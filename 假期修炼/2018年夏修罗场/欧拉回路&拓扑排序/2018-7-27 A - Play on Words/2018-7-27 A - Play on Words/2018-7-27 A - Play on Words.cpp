// 2018-7-27 A - Play on Words.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int in[26], out[26];
int fat[26];
int vis[26];
void init() {
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 26; i++) fat[i] = i;
}
int findf(int a) {
	if (a == fat[a]) return a;
	else return fat[a] = findf(fat[a]);
}
void unionNode(int a, int b) {
	int x = findf(a), y = findf(b);
	if (x != y) fat[a] = fat[b];
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		init();
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			char str[1005];
			cin >> str;
			int a = str[0] - 'a', b = str[strlen(str) - 1] - 'a';
			out[a]++, in[b]++;
			unionNode(a, b);
			vis[a] = vis[b] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) findf(i);
		for (int i = 0; i < 26; i++) {
			if (vis[i] && fat[i] == i) cnt++;
		}
		bool loop=true, path=false;
		for (int i = 0; i < 26; i++) {
			if (in[i] != out[i]) loop = false;
		}
		int count1=0, count2 = 0,count3=0;
		for (int i = 0; i < 26; i++) {
			if (in[i] != out[i]) {
				count1++;
				if (in[i] - out[i] == 1) count2++;
				else if (out[i] - in[i] == 1) count3++;
			}
		}
		if (count1 == 2 && count2 == 1 && count3 == 1) path = true;
		if (cnt > 1) cout << "The door cannot be opened." << endl;
		else if (loop || path) cout << "Ordering is possible." << endl;		else cout<< "The door cannot be opened." << endl;
	}
    return 0;
}

