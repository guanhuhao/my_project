// 2018-9-19 有序表删除元素.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int a[100]; 
int main()
{
	int n = 10;
	cout << "输入原表长度：" << endl;
	cin >> n;
	cout << "输入有序表元素（升序）" << endl;      //建立有序表
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << "输入你要删除元素的区间:" << endl;
	int mini, maxi,l=n,r=-1;
	cin >> mini >> maxi;
	for (int i = 0; i < n; i++) {
		if (a[i] <= mini)l = i;
		if (a[i] < maxi)r = i;
	}
	for (int i = 1; r + i < n; i++) a[l + i] = a[r + i];
	n -= r - l;

	cout << "删除后表为：" << endl;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
	cout << "查找O（n）可用二分查找优化为为O（logn），删除复杂度为O（n），总复杂度O（n）" << endl;
	cout << endl;
    return 0;
}

