// 2018-6-9 POJ2431 Expedition.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e6 + 10;
int line[maxn];
int main()
{
	int n;
	int l, s;
	priority_queue<int> que;
	memset(line, 0, sizeof(line));

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		line[tem1] = tem2;
	}
	cin >> l >> s;

	int poi = l;
	int ans = 0;
	que.push(s);
	while (poi > 0 && !que.empty()) {
		int top = que.top();
		//cout << "1  " << que.top() << endl;
		que.pop();
		for (int i = poi-1; i >= poi - top && i >= 0; i--)
			if (line[i] != 0)
				que.push(line[i]); 
		poi = poi - top;
		//cout << poi << endl;
		ans++;
	}
	if (l == 0) cout << 0 << endl;
	else poi > 0 ? cout << -1 << endl : cout << ans-1 << endl;
    return 0;
}

