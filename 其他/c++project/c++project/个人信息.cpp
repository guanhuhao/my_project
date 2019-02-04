#pragma once 
#include "stdafx.h"
#include "个人信息.h"
#include "工具.h"
int value_scorll(person_interface *p);									//经验条  edit by wt                     UI优化by ghh  
person_interface *creatlist();											//创建存储用户信息的链表 // edit by wt
void printlist(person_interface *p1, char userName[]);					//打印链表信息到控制台 // edit by wt
void PersonInterface(char userName[]);									//个人界面 // edit by wt                 UI优化by ghh



int value_scorll(person_interface *p)
{
	int i;//与经验值同步
	printf("	              EXP：");
	//printf("\n%d	%d	%d\n", p->empiricalvalue, p->levelup, (double)p->empiricalvalue / (double)p->levelup);
	double tem = ((double)p->empiricalvalue / (double)p->levelup) * 40;
	for (i = 0; i < tem; i++)
	{
		printf("■");
	}
	for (; i < 40; i++)
	{
		printf("%c ", 16);
	}
	printf("  %.2lf%%\n", (double)p->empiricalvalue / (double)p->levelup*100);
	//printf("\n\n***************************************************************************************");
	return 0;
}  


person_interface *creatlist()//创建存储用户信息的链表 // edit by wt
{
	person_interface *head = NULL, *tail = head, *p = NULL;


	FILE *fpRead = fopen("person_message.txt", "r+");
	if (fpRead == NULL)//文件不存在
	{
		printf("文件打开失败！\n");
		exit(0);
	}
	else//文件存在
	{
		while (!feof(fpRead))//对整个文档进行读取
		{

			p = (person_interface*)malloc(sizeof(person_interface));
			fscanf(fpRead, "ID: %06d	用户名: %15s	金币: %8d    个人等级: %6d    经验值: %4d    当前升级所需经验: %6d	牧场等级: %3d	当前容量: %3d	总容量: %d\n", &p->ID, p->username, &p->money, &p->level, &p->empiricalvalue, &p->levelup, &p->pasturelevel, &p->currentNum, &p->allNum);
			if (head == NULL)
				head = p;
			else
				tail->next = p;
			tail = p;
		}
		p->next = NULL;
	}
	fclose(fpRead);	
	return head;
}


void printlist(person_interface *p1, char userName[])//打印链表信息到控制台 // edit by wt
{
	char kongge[100] = { "*                                                                                     *" };
	person_interface *p = p1;
	int flag1 = 0;
	int flag2 = 0;
	while (p != NULL)
	{
		flag1++;
		if (strcmp(p->username, userName) == 0)
		{ 
			printf("\n\n\n                                                         个人信息\n\n");
			printf("	              ***************************************************************************************\n");
			printf("	              *  ID: %06d                                                                         *\n	              %s\n",p->ID,kongge);
			printf("	              *  用户名: %-10s                                                                 *\n	              %s\n", p->username,kongge);
			printf("	              *  金币: %-10d                                                                   *\n	              %s\n", p->money,kongge);
			printf("	              *  个人等级: %-d                                                                        *\n	              %s\n", p->level,kongge);
			printf("	              *  经验值: %4d/%-5d                                                                 *\n	              %s\n", p->empiricalvalue, p->levelup,kongge);
			printf("	              *  牧场等级: %-2d                                                                       *\n	              %s\n",  p->pasturelevel,kongge);
			printf("	              *  当前容量: %-2d/%-2d                                                                    *\n	              %s\n", p->currentNum, p->allNum,kongge);
			printf("	              ***************************************************************************************\n\n");
			value_scorll(p);
		}
		if (strcmp(p->username, userName) != 0)
		{
			flag2++;
		}
		p = p->next;
	}
	if (flag1 == flag2)
	{
		printf("找不到用户信息！\n");
		_Countdown("系统将于", 5, "s后退出……");
		exit(1);
	}
}


void PersonInterface(char userName[])
{
	char input[30];
	char temp[20];
	strcpy(temp, userName);
	//temp[strlen(temp) - 1] = '\0';
	while (1)
	{

		system("cls");
		person_interface *p;
		p = creatlist();
		printlist(p, temp);
		gotoxy(70,28);
		printf("Tips:请输入exit返回上一级菜单^_^\n");
		gotoxy(0, 24);
		printf("	              Command:");
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else
		{
			printf("指令错误！\n");
			_Countdown("	(", 3, "秒后转入主页面……)");
		}
	}
}