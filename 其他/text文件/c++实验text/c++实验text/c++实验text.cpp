// c++实验text.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int _find(char a[], fstream &fp)            //查找文件字段+移动句柄位置			edit by ghh
{
	char content[105];
	while (fp.getline(content,100))
		if (strcmp(content, a) == 0) return 1;
	return 0;
}
class animals
{
public:
	int num;
	char breed[30];
	int age;
	double weight;
	double value_pre_kilo;
	double value;
	double weight_pre_month;
	char jianjie[200];
	class animals *next;
	animals(int nn = 0, char b[30] = "\\", int a = 0, double w = 0.0, double val_pre = 0.0, double val = 0.0, double wei_pre = 0.0, char j[200] = "\\") { num = nn; strcpy(breed, b); age = a; weight = w; value_pre_kilo = val_pre; value = val; weight_pre_month = wei_pre; strcpy(jianjie, j); }
};
int _scanf_animal(fstream &fp, animals &a)
{
	fp.ignore(100, ':') >> a.num;
	fp.ignore(100, ':') >> a.breed;
	fp.ignore(100, ':') >> a.age;
	fp.ignore(100, ':') >> a.weight;
	fp.ignore(100, ':') >> a.value_pre_kilo;
	fp.ignore(100, ':') >> a.value;
	fp.ignore(100, ':') >> a.weight_pre_month;
	return 0;
}
int main()
{
	string a;

	fstream fp;
	fp.open("text.txt");
	fp << "hahahahha" << endl;
	return 0;
}

