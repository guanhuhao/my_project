// 2018-9-19 线性表并归排序.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct List {
	int v;
	List* next;
};
int main()
{
	List* head = (List*)malloc(sizeof(List));
	List* tail = head;
	tail->next = NULL;
	int n;
	cout << "请输入原数组大小：" << endl;
	cin >> n;
	cout << "请输入数组元素：" << endl;
	for (int i = 0; i < n; i++) {
		List* tem = (List*)malloc(sizeof(List));
		cin >> tem->v;
		tem->next = NULL;
		tail->next = tem;
		tail = tail->next;
	}
	int mid;
	cout << "请输入划分数：" << endl;
	cin >> mid;
	List* p = head;
	for (int i = 0; i < n; i++) {
		if (p->next->v < mid) {
			p = p->next;
			continue;
		}
		tail->next = p->next;
		p->next = p->next->next;
		tail = tail->next;
		tail->next = NULL;
	}
	p = head->next;
	cout << "操作后链表为：" << endl;
	while (p != NULL) {
		cout << p->v << " ";
		p = p->next;
	}
	cout << endl;
    return 0;
}

