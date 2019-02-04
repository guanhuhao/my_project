// 线性表（C语言实现）.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
#define INIT_CAP 1
template <class Elem>
struct List {
	int max_capacity;
	int cur_capacity;
	Elem *head;

	bool check();
	bool init();
	void destroy();
	bool empty();
	int size();
	void push(Elem a);
	Elem& operator[](int a);
	bool insert(int pos, int val);
	bool del(int a);
	bool pop();
	int expend();
	int narrow();
};
template<typename Elem> bool List<Elem>::init() {
	max_capacity = INIT_CAP;
	cur_capacity = 0;
	head = (Elem*)malloc(sizeof(Elem)*max_capacity);
	return !(head == NULL);
}
template<class Elem> bool List<Elem>::check() {
	return cur_capacity >= max_capacity;
}
template<class Elem> void List<Elem>::destroy() {
	free(head);
}
template<class Elem> bool List<Elem>::empty() {
	return cur_capacity == 0;
}
template<class Elem> int List<Elem>::size() {
	return cur_capacity;
} 
template<class Elem> void List<Elem>::push(Elem a) {           
	if (check()) expend();
	head[cur_capacity] = a;
	cur_capacity++;
} 
template<class Elem> Elem& List<Elem>::operator[](int a) {
	if (a >= cur_capacity) exit(1);
	return head[a];
}
template<class Elem> bool List<Elem>::insert(int pos,int val) {	
	if (pos > cur_capacity) return false;	
	if (check()) expend();
	for (int i = cur_capacity; i > pos; i--)
		head[i] = head[i - 1];
	head[pos] = val;
	cur_capacity++;
	return true;
}
template<class Elem> bool List<Elem>::del(int a) {
	if (empty())return false;
	for (int i = a; i < n - 1; i++) a[i] = a[i + 1];
	cur_capacity--;	
	if (cur_capacity < max_capacity / 4) narrow();
	return true;
}
template<class Elem> bool List<Elem>::pop() {
	if (empty()) return false;
	cur_capacity--;
	if (cur_capacity < max_capacity / 4) narrow();
}
template<class Elem> int List<Elem>::expend() {
	Elem * p = (Elem*)malloc(2*max_capacity * sizeof(Elem));
	if (p == NULL) return -1;	
	max_capacity *= 2;
	for (int i = 0; i < cur_capacity; i++) p[i] = head[i];
	free(head);
	head = p;
	return max_capacity;
}
template<class Elem> int List<Elem>::narrow() {
	Elem *p = (Elem*)malloc(max_capacity * sizeof(Elem));
	if (p == NULL) return -1;
	max_capacity /= 2;
	for (int i = 0; i < cur_capacity; i++) p[i] = head[i];
	free(head);
	head = p;
}


int main()


    return 0;
}

