// 2018-6-24 B. Getting an A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > que;
int main()
{
	int n;
	int sum=0;
	int ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		que.push(tem);
		sum += tem;
	}
	for (int i = 0; i < n; i++) {
		if ((int)((double)sum / n+0.5) == 5) break;
		int tem = que.top();
		que.pop();
		ans++;
		sum = sum - tem + 5;
		que.push(5);
	}
	cout << ans << endl;
    return 0;
}

