// 2018-9-19 多项式加法.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct mul {
	int xi, ci;
	mul* next;
};
int main()
{
	int n;
	cout << "请输入多项式项数：" << endl;
	cin >> n;
	mul* head = (mul*)malloc(sizeof(mul));
	mul* tail=head;
	tail->next = NULL;
	cout << "输入第一个多项式：第一项为系数，第二项为次数，请按升序输入：" << endl;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		mul* tem = (mul*)malloc(sizeof(mul));
		tem->xi = tem1;
		tem->ci = tem2;
		tem->next = NULL;
		tail->next = tem;
		tail = tail->next;
	}
	cout << "请输入第二个多项式项数：" << endl;
	cin >> n;
	mul* p = head;
	cout << "输入第二个多项式：第一项为系数，第二项为次数，请按升序输入：" << endl;
	for (int i = 0; i < n; i++) {
		int tem1, tem2;
		cin >> tem1 >> tem2;
		while (p->next!=NULL&&p->next->ci < tem2) p = p->next;
		if (p->next != NULL&&p->next->ci == tem2) p->next->xi += tem1;
		else {		
			mul* tem = (mul*)malloc(sizeof(mul));
			tem->xi = tem1;
			tem->ci = tem2;
			if (p->next == NULL) {
				tem->next = NULL;
				p->next = tem;
				p = p->next;
			}
			else {
				tem->next = p->next;
				p->next = tem;
			}
		}
	}
	p = head->next;
	int k = 1;
	while (p != NULL) {
		cout << "第" << k++ << "项：  系数:" << p->xi << "   次数:" << p->ci << endl;
		p = p->next;
	}
    return 0;
}

