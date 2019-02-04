// 2018-8-17 C. Bracket Subsequence.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
deque<char> sta;
int main()
{
	int n, m;
	string str;
	cin >> n >> m;
	cin >> str;
	int tem = (n - m) / 2;
	for (int i = 0; i < n; i++) {
		if (tem && !sta.empty() && sta.back() == '('&&str[i] == ')') {
			sta.pop_back();
			tem--;
			continue;
		}
		sta.push_back(str[i]);
		
	}
	while (!sta.empty()) {
		cout << sta.front();
		sta.pop_front();
	}
	cout << endl;
    return 0;
}

