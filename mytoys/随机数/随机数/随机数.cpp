// 随机数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	int a, b;
	srand(time(NULL));
	cout << "输入最小的数:" << endl;
	cin >> a ;
	cout << "输入最大的数:" << endl;
	cin >> b;

	while (1) {
		system("cls");
		cout << a + (rand() % (b - a)) << endl<<endl;
		cout << "摁0退出，其他键继续生成随机数" << endl;
		char a =getchar();
		if (a == '0') break;
		
	}
    return 0;
}

