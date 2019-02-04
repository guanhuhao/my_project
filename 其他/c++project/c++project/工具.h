#pragma once
#include<bits/stdc++.h>
using namespace std;
class animals
{
private:
	string breed;
	int age;
	double weight;
	double value_pre_kilo;
	double value;
	double weight_pre_month;
	string jianjie;
public:
	friend ostream & operator << (ostream &out, animals &a);
	friend istream & operator >> (istream &in, animals &a);
	string get_breed() { return breed; }
	int get_age() { return age; }
	double get_weight() { return weight; }
	double get_value_pre_kilo() { return value_pre_kilo; }
	double get_value() { return value;}
	double get_weight_pre_month() { return weight_pre_month; }
	string get_jianjie() { return jianjie; }
	animals(const animals & a) { breed = a.breed; age = a.age; weight = a.weight; value_pre_kilo = a.value_pre_kilo; value = a.value; weight_pre_month = a.weight_pre_month; }
	animals(char b[30] = "\\", int a = 0, double w = 0.0, double val_pre = 0.0, double val = 0.0, double wei_pre = 0.0, char j[200] = "\\") {breed = b; age = a; weight = w; value_pre_kilo = val_pre; value = val; weight_pre_month = wei_pre; jianjie = j; }
	double change_weight(double w, double p) { return weight = w + p*((double)(rand() % 1000) / 4000 + 0.8);  }
	double check_value() { return value=weight*value_pre_kilo; }
	int change_age() { return ++age; }

};
void gotoxy(int x, int y);                            //光标跳转函数本体
int _find(char a[], fstream &fp);									    //查找文件字段+移动句柄位置     edit by ghh
int _Countdown(char text1[1000], int num, char text2[1000]);          //倒计时+报错提示 
int _cost(int num, char name[]);         //修改个人金币         edit by ghh
int _find_scanf(char target[],fstream &fp);
