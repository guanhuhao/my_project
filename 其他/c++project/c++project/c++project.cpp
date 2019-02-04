// c++project.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<bits/stdc++.h>
#include <windows.h>
#include "个人信息.h"
#include "工具.h"
#include "贪吃蛇.h"
using namespace std;
int _next_month(char name[]);


bool cmp(animals &a, animals &b)
{
	return a.get_value() > b.get_value();
}

int  _my_farm(char name[])          //我的农场界面+出售动物+排序整理
{
	//FILE *fp;
	fstream fp;
	fstream person;

	char tem[200];
	string Command;
	animals my_animal[11];
	HWND window = GetConsoleWindow();
	SetWindowPos(window, HWND_TOP, 150, 80, 0, 0, SWP_NOSIZE);
	system("mode con cols=150 lines=43  ");
	fp.open("pasture_user_list.txt", ios::in | ios::out);
	person.open("person_message.txt", ios::in | ios::out);

	strcpy(tem, "user:");
	strcat(tem, name);
	if (!_find(tem, fp))
	{
		cout<<"                   用户信息读取错误，摁任意键退出！";
		getchar();
		exit(1);
	}
	_find("animal:", fp);
	int i = 0;
	while (++i <= 10) {
		int tem;
		fp.ignore(100, ':') >> tem;
		fp >> my_animal[i];
	}
	while (1)
	{

		system("cls");
		fp.clear();
		fp.seekg(ios::beg);
		fp.seekp(ios::beg);
		strcpy(tem, "user:");
		strcat(tem, name);

		if (!_find(tem, fp))
		{		
			cout<<"用户信息读取错误，摁任意键退出！";
			getchar();
			exit(1);
		}

		cout<<"\n                                                             ◆   │  我的牧场~ │   ◆\n";
		cout<<"                                                                 ━━━━━━━━━━━━━━━━\n\n";
		cout<<"			                 ┌──────────────────────────────────────────────────────────────┐\n";
		while (1)         //可能有问题
		{
			fp.getline(tem, 200);
			if (strcmp(tem, "animal:") == 0) break;
			printf("			                 │  %-60s│\n", tem);
		}
		cout<<"			                 └──────────────────────────────────────────────────────────────┘\n";
		cout<<"\n";
		tem[strlen(tem) - 1] = '\0';
		cout<<"                    _____________________________________________________________________________________________________________\n";
		cout<<"                   │┌──────────────────────────────────────────────────────────────────────────────────────────────────────────┐│\n";
		cout<<"                   ││                                                                                                          ││\n";
		printf("                   ││                                                %s                                                    ││\n", tem);
		cout<<"                   ││                                                                                                          ││\n";

		i = 0;
		while (++i <= 10)
		{
			printf("                   ││   · 栏号:%-6d  种类:%-10s  年龄:%-4d  重量:%-7.2lf  单价:%-6.2lf  总价:%-8.2lf  生长速度:%-6.2lf  ││\n",i, my_animal[i].get_breed().c_str(), my_animal[i].get_age(), my_animal[i].get_weight(), my_animal[i].get_value_pre_kilo(), my_animal[i].get_value(), my_animal[i].get_weight_pre_month());
		}
		cout<<"                   ││                                                                                                          ││\n";
		cout<<"                   └└──────────────────────────────────────────────────────────────────────────────────────────────────────────┘┘\n";
		cout<<"\n                          1.sale animal                        出售动物\n";
		cout<<"                          2.reset                              整理牧场信息(动物价格降序)\n";
		cout<<"                          3.save&exit                          保存并返回上级页面\n\n";
		cout<<"                            Command:";
		getline(cin, Command);
		
		if ("sale animal" == Command)
		{
			int tem;
			cout<<"                           输入你要出售的动物的栏号：";
			cin >> tem;
			if (my_animal[tem].get_breed()=="空")
			{
				printf("动物不存在，请重试！(按任意键继续……)");
				getchar();
				break;
			}
			int jinbi = _cost(-(int)(my_animal[tem].get_value()), name);


			int jingyan = (int)my_animal[tem].get_weight();	

			my_animal[tem] = animals("空",0,0,0,0,0 );

			char tem1[100];
			person.seekg(0,ios::beg);person.seekp(0,ios::beg);
			strcpy(tem1, name);
			//tem1[strlen(name) - 1] = '\0';
			_find_scanf(tem1, person);
			_find_scanf("个人等级:", person);
			int cur_exp, max_exp, level, rongliang, pasture, sumzong;

			person >> level; 
			person.ignore(100, ':') >> cur_exp;
			person.ignore(100, ':') >> max_exp;
			person.ignore(100, ':') >> pasture;
			person.ignore(100, ':') >> rongliang;
			person.ignore(100, ':') >> sumzong;

			cur_exp = cur_exp + jingyan;
			if (cur_exp > max_exp)
			{
				cur_exp = cur_exp - max_exp;
				max_exp *= 2;
				level++;
			}

			person.seekg(0,ios::beg);person.seekp(0,ios::beg);
			_find_scanf(tem1, person);
			_find_scanf("个人等级:", person);
			person.seekp(person.tellg(), ios::beg);		
 
			person << " " << left << setw(6) << level << "    经验值: " << setw(4) << cur_exp << "    当前升级所需经验: " << setw(6) << max_exp << "	牧场等级: " << setw(3) << pasture << "	当前容量: " << setw(3) << rongliang - 1 << "	总容量: " << sumzong<<endl;
			getchar();
		}
		else if (Command== "save&exit")
		{
			fp.clear();
			fp.seekg(ios::beg);fp.seekp(ios::beg);
			strcpy(tem, "user:");
			strcat(tem, name);
			_find(tem, fp);
			_find("animal:", fp);
			i = 0;
			fp.seekp(fp.tellg(), ios::beg);
			while (++i <= 10)
			{
				fp << "栏号:" << left << setw(6) << i;
				fp << my_animal[i];
			}
			printf("                            已保存，摁任意键返回！\n");
			getchar();
			break;
		}
		else if (Command== "reset")
		{
			sort(my_animal + 1, my_animal + 11,cmp);
		}
		else
		{
			printf("                            指令输入错误！摁任意键返回\n");
			getchar();
		}
	}
	fp.close();
	person.close();
	SetWindowPos(window, HWND_TOP, 200, 100, 0, 0, SWP_NOSIZE);
	system("mode con cols=130 lines=40  ");
	//fprintf(fp,"hahahha\n");
	
	
	return 0;
}
int _player_menu(char name[])           //玩家页面显示     edit by ghh   
{
	srand((unsigned int)(time(NULL)));
	string Command;
	while (1)
	{
		system("cls");
		gotoxy(70, 35);
		printf("tips：输入对应括号内的命令进入不同场景w\n\n");
		gotoxy(0, 2);
		cout<<"\n                                                       玩家（Player）界面\n\n";
		cout<<"                                               ┌───────────────────────────────┐\n";
		cout<<"                                               │             指令集            │\n";
		cout<<"                                               └───────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           1.personal message          显示个人信息               │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           2.my pasture                我的牧场                   │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           3.enter store               进入商店                   │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           4.next month                继续游戏，进入下一个月     │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           5.play game                 贪吃蛇游戏                 │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n";
		cout<<"                            ┌──────────────────────────────────────────────────────────────────┐\n";
		cout<<"                            │           6.exit                      返回上级界面               │\n";
		cout<<"                            └──────────────────────────────────────────────────────────────────┘\n\n\n";
		cout<<"                             Command:";
		getline(cin,Command);
		if      (Command == "personal message")    PersonInterface(name);
		else if (Command == "my pasture")     _my_farm(name);
		else if (Command == "enter store"); //  _enter_store(name);
		else if (Command == "next month")    _next_month(name);
		else if (Command == "play game")      tanchishe(name);
		else if (Command == "exit")                  break;
		else
		{
			cout<<"\n                             指令输入错误，请重试！（摁任意键继续……）";
			getchar();
		}

	}
	return 0;
}
int main()
{
	system("mode con cols=130 lines=40  ");
	HWND window = GetConsoleWindow();
	SetWindowPos(window, HWND_TOP, 200, 100, 0, 0, SWP_NOSIZE);
	_player_menu("guanhuhao");
    return 0;
}

int _next_month(char name[])			 //游戏进程+1月     edit by ghh
{
	int i;
	//FILE *fp;
	fstream fp;
	char tem[100];
	fp.open("pasture_user_list.txt");

	strcpy(tem, "user:");
	strcat(tem, name);
	if (!_find(tem, fp) || !_find("animal:", fp))
	{
		printf("                             未找到用户信息，摁任意键返回……");
		getchar();
		return 0;
	}
	animals my_animal[11];
	for (i = 1; i <= 10; i++) {
		int tem;
		fp.ignore(100, ':') >> tem;
		fp >> my_animal[i];
	}
	for (i = 1; i <= 10; i++)
	{
		if (my_animal[i].get_breed()== "空")         continue;
		my_animal[i].change_weight(my_animal[i].get_weight(), my_animal[i].get_weight_pre_month());
		my_animal[i].change_age();
		my_animal[i].check_value();
	}
	fp.seekg(0, ios::beg);
	fp.seekp(0, ios::beg);
	_find(tem, fp);
	_find("animal:", fp);
	fp.seekp(fp.tellg(), ios::beg);
	for (i = 1; i <= 10; i++) {
		fp << "栏号:" << left << setw(6) << i;
		fp << my_animal[i];
	}
	fp.close();
	return 0;
}

