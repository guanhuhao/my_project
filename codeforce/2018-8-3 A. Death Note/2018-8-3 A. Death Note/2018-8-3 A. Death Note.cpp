// 2018-8-3 A. Death Note.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
	queue<int> que;
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int tem;
		cin >> tem;
		sum += tem;
		que.push(sum / m);
		sum -= sum / m*m;
	}
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
    return 0;
}

