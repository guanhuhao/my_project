// cpu.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <bits/stdc++.h>
using namespace std;
enum CPU_RANK {P1=1,P2,P3,P4,P5,P6,P7};       //ö�ٱ�������
class CPU                                       //CPU�ඨ��
{
public:
	void run() { cout << "CPU_RANK:" << rank << endl << "frequence:" << freq << endl << "voltage:" << vol << endl; }
	void stop() { cout << "do noting" << endl; }
	CPU(CPU_RANK rr = P1, int ff = 0, float vv = 0) { freq = ff; vol = vv; rank = rr; cout << "����CPU���캯��" << endl; }
	CPU(const CPU &a) { freq = a.freq; vol = a.vol; rank = a.rank; cout << "����CPU���ƹ��캯��" << endl; }
	~CPU() { cout << "����CPU��������" << endl; }
private:
	int freq;
	float vol;
	CPU_RANK rank;
};
class RAM                   //RAM�ඨ��
{
public:
	void run() { cout << "I don't no what should i do ..." << endl; }
	RAM(int rr = 0) { rank = rr; cout << "����RAM���캯��" << endl;}
	RAM(const RAM &a) { rank = a.rank; cout << "����RAM���ƹ��캯��" << endl;}
	~RAM() { cout << "����RAM��������" << endl; }
private:
	int rank;

};
class CDRAM               //CDRAM����
{
public:
	void run() { cout << "I don't no what should i do ..." << endl; }
	CDRAM(int rr=0) { rank = rr;  cout << "����CDRAM���캯��" << endl; }
	CDRAM(const CDRAM &a) { rank = a.rank; cout << "����CDRAM���ƹ��캯��" << endl;}
	~CDRAM() { cout << "����CDRAM��������" << endl; }
private:
	int rank;
};
class COMPUTER                //COMPUTER�ඨ��
{
public:
	COMPUTER(CPU a=CPU(), RAM b=RAM(), CDRAM c=CDRAM()) { cpu = a;  ram = b; cdram = c;}
	void run() { cout << "I don't no what should i do ..." << endl; }
	~COMPUTER() { cout << "����COMPUTER��������" << endl; }
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
	void show() { cout << nian << "��" << yue << "��" << ri << "��"; }
};
class People
{
private:
	int number, idcard;
	char sex[20];
	Date birthday;
public:
	People(int num = 0, int id = 1, char s[] = "��", Date bb = Date(1970, 1, 1)) { number = num; idcard = id; strcpy(sex, s);birthday=bb; }
	People(const People &a) :number(a.number), idcard(a.idcard), birthday(a.birthday) { strcpy(sex, a.sex); }
	inline void show() { cout << "��ţ�" << number << "  �Ա�" << sex << "  ���֤�ţ�" << idcard << "  "; birthday.show(); cout << endl; };
	~People() {};
};
int main()
{
	COMPUTER a;
	getchar();
    return 0;
}

