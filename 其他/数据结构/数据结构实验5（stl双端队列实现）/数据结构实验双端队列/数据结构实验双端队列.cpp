// 数据结构实验双端队列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
deque<int> que;

#define init_size 10;
template<typename Data>
struct P {
	Data data;
	P *next;
};
template <typename Elem>
struct my_deque{
private:
	P<Elem> *head;
	P<Elem> *tail;
	int SIZE;

public:	
	my_deque();   //checked
	void push_back(Elem a);//checked
	void push_front(Elem a);//checked
	int pop_back();//checked
	int pop_front();//checked
	Elem front();//checked
	Elem back();//checked
	int size();//checked
	int empty();//checked
	void clear();//checked
	void show(); //checked
};
template<typename Elem> my_deque<Elem>::my_deque() {
	SIZE = 0;
	head = (P<Elem>*)malloc(sizeof(P<Elem>));
	tail = head;
	tail->next = NULL;
}
template<typename Elem> void my_deque<Elem>::push_back(Elem a) {
	P<Elem>* tem = (P<Elem>*)malloc(sizeof(P<Elem>));
	tem->data = a;
	tail->next = tem;
	tail = tail->next;
	tail->next = NULL;
	SIZE++;
}
template<typename Elem> void my_deque<Elem>::push_front(Elem a) {
	P<Elem> *tem = (P<Elem>*)malloc(sizeof(P<Elem>));
	tem->data = a;
	tem->next = head->next;
	head->next = tem;
	SIZE++;
	if (SIZE == 1) tail = head->next;
}
template<typename Elem> int my_deque<Elem>::pop_back() {
	if (SIZE == 0) return -1;
	P<Elem>* tem = head;
	while (tem->next->next != NULL) tem = tem->next;
	tem->next = NULL;
	free(tail);
	tail = tem;
	SIZE--;
	return 0;
}
template<typename Elem> int my_deque<Elem>::pop_front() {
	if (SIZE == 0) return -1;
	P<Elem>* tem = head->next;
	head->next = tem->next;
	free(tem);
	SIZE--;
	return 0;
}
template<typename Elem> Elem my_deque<Elem>::back() {
	return tail->data;
}
template<typename Elem> Elem my_deque<Elem>::front(){
	return head->next->data;
}
template<typename Elem> int my_deque<Elem>::size() {
	return SIZE;
}
template<typename Elem> int my_deque<Elem>::empty() {
	return SIZE == 0;
}
template<typename Elem> void my_deque<Elem>::clear() {
	while (head->next=NULL) {
		P<Elem>* tem = head->next;
		head->next = tem->next;
		free(tem);
	}
	tail = head;
	SIZE = 0;
}
template<typename Elem> void my_deque<Elem>::show() {
	P<Elem> *tem = head->next;
	while (tem != NULL) {
		cout << tem->data << " ";
		//cout << 1 << " ";
		tem = tem->next;
	}
	cout << endl;
}
int main()
{
	my_deque<int> text;
	cout << "已建立双端队列！" << endl;
	for (int i = 0; i < 5; i++) {
		text.push_back(rand() % 10);
	}
	cout << "初始序列为：";
	text.show();
	for (int i = 0; i < 10; i++) {
		int tem = rand() % 2;
		if (tem == 1) {
			tem = rand() % 2;
			if (tem == 1) {
				int tem2 = rand() % 10;
				cout << "从尾部插入元素:" << tem2 << endl;
				cout << "现在序列为：";
				text.push_back(tem2);
				text.show();
				cout << "队列头部元素为：" << text.front() << "  " << "队列尾部元素为：" << text.back() << "  " << "现在大小为:" << text.size() << endl;
			}
			else {
				int tem2 = rand() % 10;
				cout << "从头部插入元素:" << tem2 << endl;
				cout << "现在序列为：";
				text.push_front(tem2);
				text.show();
				cout << "队列头部元素为：" << text.front() << "  " << "队列尾部元素为：" << text.back() << "  " << "现在大小为:" << text.size() << endl;
			}
		}
		else {
			tem = rand() % 2;
			if (tem == 1) {
				cout << "从尾部弹出元素" << endl;
				cout << "现在序列为：";
				text.pop_back();
				text.show();
				cout << "队列头部元素为：" << text.front() << "  " << "队列尾部元素为：" << text.back() << "  " << "现在大小为:" << text.size() << endl;
			}
			else {
				cout << "从头部弹出元素"  << endl;
				cout << "现在序列为：";
				text.pop_front();
				text.show();
				cout << "队列头部元素为：" << text.front() << "  " << "队列尾部元素为：" << text.back() <<"  "<< "现在大小为:" << text.size() << endl;
			}
		}
		cout << endl;
	}
	cout << "最终序列为：";
	text.show();
	cout << "双端队列大小为：" << text.size() << endl;
	cout << "清除所有数据！" << endl;
	text.clear();
	cout << "现在序列为：";
	cout << "现在大小为:" << text.size() << endl;
    return 0;
}

