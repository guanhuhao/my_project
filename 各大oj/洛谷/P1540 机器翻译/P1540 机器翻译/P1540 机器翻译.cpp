// P1540 机器翻译.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
using namespace std;
list<int> my;
int main()
{
	int M, N;
	int ans = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		int tem;
		cin >> tem; 
		if (find(my.begin(), my.end(),tem)==my.end())
		{
			if (my.size() == M) my.pop_front();
			my.push_back(tem);
			ans++;
		}
	}
	cout << ans<<endl;
    return 0;
}
/*int main()
{
	list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	; // 查找list中是否有元素“10”
	if (find(lst.begin(), lst.end(), 10) != lst.end()) // 找到了
	{
		// do something
	}
	else // 没找到
	{
		// do something
	}
	return 0;
}*/

