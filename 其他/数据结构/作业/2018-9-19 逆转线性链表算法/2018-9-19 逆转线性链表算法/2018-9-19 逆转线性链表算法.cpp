// 2018-9-19 逆转线性链表算法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
struct List {
	int v;
	List *next;
};
void Reverse(List *head,List *&ans_head) {
	List* p = head;
	while (p != NULL) {
		List* tem = (List*)malloc(sizeof(List));
		tem->v = p->v;
		tem->next = ans_head;
		ans_head = tem;
		p = p->next;

	}
}
int main()
{	

	List* head = (List*)malloc(sizeof(List));	   //新建原链表
	List* tail = head;
	int n;
	cout << "请输入你要新建的链表长度：" << endl;
	cin >> n;
	cout << "请依次输入链表元素" << endl;
	cin >> head->v ;
	for (int i = 1; i < n; i++) {
		List* tem = (List*)malloc(sizeof(List));
		cin >> tem->v;
		tem->next = NULL;
		tail->next= tem;
		tail = tem;
	}
	
	List* ans_head=NULL;			//头插法建立新链表
	Reverse(head, ans_head);       //执行算法

	cout << endl << "逆序链表:" << endl;   //输出
	List* p = ans_head;
	while (p != NULL) {
		cout << p->v << " ";
		p = p->next;
	}
	cout << endl;
    return 0;
}

