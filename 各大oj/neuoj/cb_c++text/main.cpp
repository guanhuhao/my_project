// cpu.cpp: 定义控制台应用程序的入口点。
//

#include <bits/stdc++.h>
using namespace std;
enum CPU_RANK {P1=1,P2,P3,P4,P5,P6,P7};       //枚举变量定义
class CPU                                       //CPU类定义
{
public:
	void run() { cout << "CPU_RANK:" << rank << endl << "frequence:" << freq << endl << "voltage:" << vol << endl; }
	void stop() { cout << "do noting" << endl; }
	CPU(CPU_RANK rr = P1, int ff = 0, float vv = 0) { freq = ff; vol = vv; rank = rr; cout << "调用CPU构造函数" << endl; }
	CPU(const CPU &a) { freq = a.freq; vol = a.vol; rank = a.rank; cout << "调用CPU复制构造函数" << endl; }
	~CPU() { cout << "调用CPU析构函数" << endl; }
private:
	int freq;
	float vol;
	CPU_RANK rank;
};
class RAM                   //RAM类定义
{
public:
	void run() { cout << "I don't no what should i do ..." << endl; }
	RAM(int rr = 0) { rank = rr; cout << "调用RAM构造函数" << endl;}
	RAM(const RAM &a) { rank = a.rank; cout << "调用RAM复制构造函数" << endl;}
	~RAM() { cout << "调用RAM析构函数" << endl; }
private:
	int rank;

};
class CDRAM               //CDRAM定义
{
public:
	void run() { cout << "I don't no what should i do ..." << endl; }
	CDRAM(int rr=0) { rank = rr;  cout << "调用CDRAM构造函数" << endl; }
	CDRAM(const CDRAM &a) { rank = a.rank; cout << "调用CDRAM复制构造函数" << endl;}
	~CDRAM() { cout << "调用CDRAM析构函数" << endl; }
private:
	int rank;
};
class COMPUTER                //COMPUTER类定义
{
public:
	COMPUTER(CPU a=CPU(), RAM b=RAM(), CDRAM c=CDRAM()) { cpu = a;  ram = b; cdram = c;}
	void run() { cout << "I don't no what should i do ..." << endl; }
	~COMPUTER() { cout << "调用COMPUTER析构函数" << endl; }
private:
	RAM ram;
	CDRAM cdram;
	CPU cpu;
};


class Date
{
private:
	int nian, yue, ri;
public:
	Date(int n=1970, int y=1, int r=1) :nian(n), yue(y), ri(r) {};
	Date(const Date &a) :nian(a.nian), yue(a.yue), ri(a.ri) {};
	void show() { cout << nian << "年" << yue << "月" << ri << "日"; }
};
class People
{
private:
	int number, idcard;
	char sex[20];
	Date birthday;
public:
	People(int num = 0, int id = 1, char s[] = "男", Date bb = Date(1970, 1, 1)) { number = num; idcard = id; strcpy(sex, s);birthday=bb; }
	People(const People &a) :number(a.number), idcard(a.idcard), birthday(a.birthday) { strcpy(sex, a.sex); }
	inline void show() { cout << "编号：" << number << "  性别：" << sex << "  身份证号：" << idcard << "  "; birthday.show(); cout << endl; };
	~People() {};
};
int main()
{
	COMPUTER a;
	getchar();
    return 0;
}

