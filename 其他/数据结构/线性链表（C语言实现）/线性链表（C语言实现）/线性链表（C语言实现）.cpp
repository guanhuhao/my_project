// 线性链表（C语言实现）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct P{
	T data;
	P *next;
};
template<typename Elem>
struct Link_list{
	P<Elem> *cur;
	P<Elem> *head;
	P<Elem> *tail;
	int size;
	
	Link_list<Elem>();
	void init();
	int push(Elem a);
	void pop();
	P<Elem>* find(Elem a);
	int insert_back(Elem posi,Elem a);
	int insert_pre(Elem posi,Elem a);
	void del(Elem posi);
	void print();
};
template<typename Elem> Link_list<Elem>::Link_list(){
	P<Elem> *headd = (P<Elem>*)malloc(sizeof(P<Elem>));
	head = headd;
	tail = head;
	tail->next = NULL;
}
template<typename Elem> void Link_list<Elem>::init() {
	size = 0;
	while (head->next != NULL) {
		P<Elem> tem = head;
		head = head->next;
		free(tem);
	}
	free(head);
	tail = head = NULL;
}
template<typename Elem> int Link_list<Elem>::push(Elem a) {
	P<Elem> *tem = (P<Elem>*)malloc(sizeof(P<Elem>));
	if (tem == NULL) return -1;
	tem->data = a;
	tem->next = NULL;
	tail->next = tem;
	tail = tem;
	size++;
	return 0;
}
template<typename Elem> void Link_list<Elem>::pop() {
	cur = head;
	while (cur->next != NULL&&cur->next->next!=NULL) cur = cur->next;
	free(cur->next);
	cur->next = NULL;
	tail = cur;
	size--;
	
}
template<typename Elem> P<Elem>* Link_list<Elem>::find(Elem a) {
	P<Elem> *pos;
	cur = head->next;
	while (cur != NULL&&(cur->data )!= a) cur = cur->next;
	if (cur == NULL) pos = NULL;
	else pos = cur;
	return pos;
}
template<typename Elem> int Link_list<Elem>::insert_back(Elem posi,Elem a) {
	P<Elem>* tem = (P<Elem>*)malloc(sizeof(Elem));
	P<Elem>* pos = find(posi);
	if (pos == NULL || tem == NULL) return -1;
	tem->data = a;
	tem->next = pos->next;
	pos->next = tem;
	return 0;
}
template<typename Elem> int Link_list<Elem>::insert_pre(Elem posi,Elem a){
	P<Elem>* tem = (P<Elem>*)malloc(sizeof(P<Elem>));
	cur = head;
	while (cur->next->data != posi)cur = cur->next;
	if (tem == NULL||cur==NULL) return -1;
	tem->data = a;
	tem->next = cur->next;
	cur->next = tem;
	return 0;
}
template<typename Elem> void Link_list<Elem>::del(Elem posi){
	cur = head;
	while (cur->next->data != posi)cur = cur->next;
	P<Elem>* tem = cur->next;
	cur->next = cur->next->next;
	free(tem);
}
template<typename Elem> void Link_list<Elem>::print() {
	cur = head->next;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	Link_list<int> test;
	//test.init();
	test.push(1);
	test.push(2);
	test.print();
	test.insert_back(1, 3);
	test.print();

    return 0;
}

