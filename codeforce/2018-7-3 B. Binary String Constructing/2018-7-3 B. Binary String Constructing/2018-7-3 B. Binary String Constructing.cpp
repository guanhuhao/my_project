// 2018-7-3 B. Binary String Constructing.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[2] ,x;
	cin >> a[0] >> a[1] >> x;
	deque<int> que;
	int flag = a[0] < a[1];
	que.push_front ( flag);
	a[flag]--;
	for (int i = 0; i < x; i++) {
		a[!que.back()]--;
		que.push_back(!que.back());
		
	}
	/*if (a[0]) {
		if (que.back() == 0) {
			for (int i = 0; i < a[0]; i++)
				que.push_back(0);
		}
		else if (que.front() == 0) {
			for (int i = 0; i < a[0]; i++)
				que.push_front(0);
		}
	}

	if (a[1]) {
		if (que.back() == 1) {
			for (int i = 0; i < a[1]; i++)
				que.push_back(1);
		}
		else if (que.front() == 1) {
			for (int i = 0; i < a[1]; i++)
				que.push_front(1);
		}
	}*/
	while (!que.empty()) {
		cout << que.front();
		if (a[que.front()]) {
			for (int i = 0; i < a[que.front()]; i++)
				cout << que.front();
			a[que.front()] = 0;
		}
		que.pop_front();
	}
}

