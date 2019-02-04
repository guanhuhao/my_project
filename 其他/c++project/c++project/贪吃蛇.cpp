#pragma once 
#include "stdafx.h"
#include <conio.h> 
#include <bits/stdc++.h>
#include <windows.h>
#include <thread>
#include "工具.h"
#define n 20
#define wide 23
#define high 40

int tanchishe(char name[]);                                          //贪吃蛇入口
void HideCursor(int a);                                   //隐藏/显示
void ball();
void body();
void direction();
int c1 = 6, c2 = 7;
char a[wide][high] = { 0 }, dir;                       //a[n][n]为整个舞台   dir为方向控制变量     num[10000]为存储动作数组

queue<char> num;

int k = 1, l = 0, END = 0, speed, jifen=0;                              //speed 为速度控制变量 end为程序判定结束变量  k和l存储尾部动作 jifen 为分数


int tanchishe(char name[])
{
	printf("  ");
	END = jifen = 0;
	k = 1; 
	l = 0;

	srand(time(NULL));
	system("cls");
	int i, j;
	char RESTART = 0;
	for (i = 0; i<wide; i++)
	{
		for (j = 0; j < high; j++)
			a[i][j] = ' ';
	}
	while (!num.empty()) num.pop();
	//for (i = 0; i < 10000; i++) num[i] = 0;
	for (i = 0; i<high; i++)
	{
		a[wide-1][i] = '*';
		a[0][i] = '*';
	}
	for (i = 0; i < wide; i++)
	{
		a[i][high - 1] = '*';
		a[i][0] = '*';
	}
	printf("\n\n                                                       牧场online の 贪吃蛇");
	printf("\n\n                                                                                                              分数：\n");
	for (i = 0; i<wide; i++)
	{
		printf("                          ");
		for (j = 0; j<high; j++)
			printf("%c ", a[i][j]);
		printf("\n");
	}
	printf("\n\n			 help:\n");
	printf("		 	 欢迎来到牧场online の 贪吃蛇，一开始屏幕中央的*就是贪吃蛇（！？）\n");
	printf("			 使用wasd来控制方向，注意玩之前先把输入法关掉（调成英文输入）\n");
	printf("			 #为本游戏设置的食物碰到就会变长\n");
	printf("			 千万注意不能让头碰到碰到所有*的东西（包括墙壁和自己）\n");
	printf("			 每次进行游戏会消耗你当前金币的30%%，但如果吃到20颗豆子就会获得什么牧场动物——贪吃蛇哦~\n\n");
	printf("			 摁回车开始游戏");
	//scanf("%d", &speed);
	getchar();
	//_costpre(30, name);
	speed = 250;
	system("cls");
	HideCursor(0);

	dir = 'w';


	thread t1(body);
	thread t3(direction);
	t1.detach();
	t3.detach();


	a[c1][c2] = '#';
	while (1)
	{		

		gotoxy(0, 0);
		printf("\n\n                                                       牧场online の 贪吃蛇");
		printf("\n\n                                                                                                              分数：%d\n",jifen);
		for (i = 0; i<wide; i++)
		{
			printf("                          ");
			for (j = 0; j<high; j++)
				printf("%c ", a[i][j]);
			printf("\n");
		}
		printf("\n\n			 help:\n");
		printf("		 	 欢迎来到牧场online の 贪吃蛇，一开始屏幕中央的*就是贪吃蛇（！？）\n");
		printf("			 使用wasd来控制方向，注意玩之前先把输入法关掉（调成英文输入）\n");
		printf("			 #为本游戏设置的食物碰到就会变长\n");
		printf("			 千万注意不能让头碰到碰到所有*的东西（包括墙壁和自己）\n");
		printf("			 每次进行游戏会消耗你当前金币的30%%，但如果吃到20颗豆子就会获得什么牧场动物——贪吃蛇哦~\n\n");
		//printf("			 摁回车开始游戏");
		Sleep(2);
		if (END == 1)
			break;
	}


	if (END == 1)
	{


		system("cls");
		gotoxy(50,13);
		printf(" GAME OVER\n");
		gotoxy(48, 15);
		printf("你获得的积分为：%d\n", jifen);
		//ExitThread(body);
		gotoxy(40, 17);
		if (jifen >= 2)
		{
			gotoxy(30, 17);
			printf("恭喜你获得了——贪吃蛇！（将自动放入你的牧场空余栏，如果无空余栏则将自动丢弃）\n");
			fstream fp;
			char tem[100];
			animals my_animal[11];
			fp.open("pasture_user_list.txt");

			strcpy(tem, "user:");
			strcat(tem, name);
			if (!_find(tem, fp))
			{
				printf("用户信息读取错误，摁任意键退出！");
				getchar();
				exit(1);
			}
			_find("animal:", fp);
			int i = 0;
			while (++i <= 10)
			{
				int tem2;
				fp.ignore(100, ':') >> tem2;
				fp >> my_animal[i];
				//cout << my_animal[i];
			}
			//getchar();
			for (i = 1; i <= 10; i++)
			{
				if (my_animal[i].get_breed()!= "空") continue;
				my_animal[i] = animals("贪吃蛇", 0, 1.0, 100.0, 1.0, 1);
				//printf("\n\n%lf	%lf\n\n", cur->weight_pre_month, my_animal[i].weight_pre_month);

				
				fp.seekg(0, ios::beg);
				fp.seekp(0, ios::beg);
				_find(tem, fp);
				_find("animal:", fp);
				i = 0;
				fp.seekp(fp.tellg(), ios::beg);

				while (++i <= 10)
				{
					fp << "栏号:" << left << setw(6) << i;
					fp << my_animal[i];
					// fprintf(fp,"栏号:%-6d  种类:%-10s  年龄:%-4d  重量:%-7.2lf  单价:%-6.2lf  总价:%-8.2lf  生长速度:%-6.2lf\n",1,"hah",1,1.0,1.0,1.0,1.0);
				}

				fstream person;
				person.open("person_message.txt");

				char tem1[30];
				int rongliang;
				strcpy(tem1, name);
				tem1[strlen(tem1) - 1] = '\0';
				_find_scanf(tem1, person);
				//fseek(person, 0, 1);
				_find_scanf("当前容量:", person);
				person >> rongliang;
				//sprintf(tem1, "%d", rongliang);
				person.seekp(person.tellg(), ios::beg);
				person << left << setw(3) << rongliang + 1;
				person.close();
			

			}

			fp.close();

		}			
		else printf("很可惜，你离贪吃蛇还有%d颗豆子的距离：:(", 20 - jifen);

		HideCursor(1);
	}
	gotoxy(50, 19);
	printf("摁回车键返回");
	getchar();

	return 0;
}


void direction()   //控制方向 线程2 direction的本体
{
	char t = 0;
	while (1)
	{
		t = _getch();
		if (END == 1)
			break;
		if (t != 'w' && t != 'a' && t != 's' && t != 'd')
			continue;
		if (dir == 'w'&&t == 's')
			continue;
		if (dir == 's'&&t == 'w')
			continue;
		if (dir == 'd'&&t == 'a')
			continue;
		if (dir == 'a'&&t == 'd')
			continue;

		dir = t;
	}

}

void body()   //控制身体的线程h1 body的本体
{
	int RL = 5, UD = 5;
	int b1 = UD, b2 = RL;
	while (1)
	{
		if (dir == 'w')
		{
			UD--;
			num.push('w');
			k++;
		}

		else if (dir == 's')
		{
			UD++;
			num.push('s');
			k++;
		}
		else if (dir == 'a')
		{
			RL--;
			num.push('a');
			k++;
		}
		else if (dir == 'd')
		{
			RL++;
			num.push('d');
			k++;
		}
		if (a[UD][RL] == '*')
		{
			END = 1;
			break;
		}
		if (a[UD][RL] == '#')
		{
			a[UD][RL] = '*';
			jifen++;
			while (1)
			{
				c1 = rand() % (wide - 2) + 1;
				c2 = rand() % (high - 2) + 1;
				if (a[c1][c2] != '*')
					break;
			}
			a[c1][c2] = '#';
		}
		else
		{
			a[b1][b2] = ' ';
			a[UD][RL] = '*';
			if (num.front() == 'w')	b1--;
			if (num.front() == 's')	b1++;
			if (num.front() == 'a')	b2--;
			if (num.front() == 'd')	b2++;
			num.pop();
		}

		Sleep(speed);


	}
	END = 1;

}
void HideCursor(int a)
{
	CONSOLE_CURSOR_INFO cursor_info[2] = { { 1, 0 }, {1,1} };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info[a]);
}
