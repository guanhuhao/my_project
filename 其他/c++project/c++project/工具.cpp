#include "stdafx.h"
#include <windows.h>
#include "����.h"

void gotoxy(int x, int y)                            //�����ת��������
{
	COORD coord = { (short)x, (short)y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int _find(char a[], fstream &fp)            //�����ļ��ֶ�+�ƶ����λ��			edit by ghh
{
	char content[105];
	while (fp.getline(content, 100))
	{

		//a[strlen(a)-1] = '\0';	
		//cout << content << endl << a << endl << strcmp(content, a) << endl;
		//getchar();
		if (strcmp(content, a) == 0) return 1;
	}

	return 0;
}

int _Countdown(char text1[1000], int num, char text2[1000])          //����ʱ+������ʾ 
{
	while (num)
	{
		printf("%s%d%s", text1, num, text2);
		Sleep(1000);
		printf("\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r\r");
		num--;
	}
	return 0;
}

int _cost(int num, char name[])          //�޸ĸ��˽��         edit by ghh
{
	fstream fp;
	int money;
	char tem[100];
	int p1;
	fp.open("person_message.txt");
	strcpy(tem, name);

	_find_scanf(tem, fp);
	fp.ignore(100,':');
	p1 = fp.tellg();
	fp >> money;

	fp.seekp(p1, ios::beg);
	fp << " " << left << setw(8) << money - num;
	return money - num;
}

int _find_scanf(char target[], fstream &fp)         //���ҵ�������			edit by ghh
{
	//printf("%s", target);
	char tem[100];
	while (fp>>tem)
	{
		if (strcmp(tem, target) == 0)
			return 1;
	}
	return 0;
}

ostream &operator <<(ostream &out, animals &a) {
	//out << "����:" << left << setw(6) << a.num;
	out << "  ����:" << left << setw(10) << a.breed;
	out << "  ����:" << left << setw(4) << a.age;
	out << "  ����:" << left << fixed << setprecision(2) << setw(7) << a.weight;
	out << "  ����:" << left << fixed << setprecision(2) << setw(6) << a.value_pre_kilo;
	out << "  �ܼ�:" << left << fixed << setprecision(2) << setw(8) << a.value;
	out << "  �����ٶ�:" << left << fixed << setprecision(2) << setw(6) << a.weight_pre_month << endl;
	return out;
}

istream &operator >>(istream &in, animals &a)
{
	//in.ignore(100, ':') >> a.num;
	in.ignore(100, ':') >> a.breed;
	in.ignore(100, ':') >> a.age;
	in.ignore(100, ':') >> a.weight;
	in.ignore(100, ':') >> a.value_pre_kilo;
	in.ignore(100, ':') >> a.value;
	in.ignore(100, ':') >> a.weight_pre_month;
	return in;
}
