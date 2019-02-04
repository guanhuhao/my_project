#pragma once
typedef  struct person// edit by wt
{
	int ID;//编号
	char username[30];//用户名
	int money;//金币
	int level;//个人等级
	int empiricalvalue;//经验值
	int levelup;//当前等级升级所需经验
	int pasturelevel;//牧场等级
	int currentNum;//当前容量
	int allNum;//总容量
	struct person *next;//用来衔接链表的指针
} person_interface;
int value_scorll(person_interface *p);									//经验条 // edit by wt
char* add_messgae_and_print(int ID, char userName[]);					//格式化写入文件 // edit by wt
person_interface *creatlist();											//创建存储用户信息的链表 // edit by wt
void printlist(person_interface *p1, char userName[]);					//打印链表信息到控制台 // edit by wt
void PersonInterface(char userName[]);									//个人界面 // edit by wt





