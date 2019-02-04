// Bracket Sequences Concatenation Problem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)3e5 + 10;
int _left[maxn] = { 0 }, _right[maxn] = { 0 };
int main()
{
	int n;
	int full=0;
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a[maxn];
		int tail = 0;
		string s;
		cin >> s;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			if (tail >= 1 && a[tail - 1] == '('&&s[i] == ')') tail--;
			else a[tail++] = s[i];
		}
		if (tail==0) {
			full++;
			continue;
		}
		if (a[tail-1] != a[0]) continue;
		if (a[tail-1] == '(') _left[tail]++;
		else if (a[tail-1] == ')') _right[tail]++;
	}

	long long ans=0;
	for (int i = 0; i < 3e5+5; i++) {
		ans = ans + (long long)_left[i] * _right[i];
	}
	ans = ans + (long long)full*full;
	cout << ans <<endl;
    return 0;
}

