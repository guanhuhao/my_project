#pragma once 
#include "stdafx.h"
#include "������Ϣ.h"
#include "����.h"
int value_scorll(person_interface *p);									//������  edit by wt                     UI�Ż�by ghh  
person_interface *creatlist();											//�����洢�û���Ϣ������ // edit by wt
void printlist(person_interface *p1, char userName[]);					//��ӡ������Ϣ������̨ // edit by wt
void PersonInterface(char userName[]);									//���˽��� // edit by wt                 UI�Ż�by ghh



int value_scorll(person_interface *p)
{
	int i;//�뾭��ֵͬ��
	printf("	              EXP��");
	//printf("\n%d	%d	%d\n", p->empiricalvalue, p->levelup, (double)p->empiricalvalue / (double)p->levelup);
	double tem = ((double)p->empiricalvalue / (double)p->levelup) * 40;
	for (i = 0; i < tem; i++)
	{
		printf("��");
	}
	for (; i < 40; i++)
	{
		printf("%c ", 16);
	}
	printf("  %.2lf%%\n", (double)p->empiricalvalue / (double)p->levelup*100);
	//printf("\n\n***************************************************************************************");
	return 0;
}  


person_interface *creatlist()//�����洢�û���Ϣ������ // edit by wt
{
	person_interface *head = NULL, *tail = head, *p = NULL;


	FILE *fpRead = fopen("person_message.txt", "r+");
	if (fpRead == NULL)//�ļ�������
	{
		printf("�ļ���ʧ�ܣ�\n");
		exit(0);
	}
	else//�ļ�����
	{
		while (!feof(fpRead))//�������ĵ����ж�ȡ
		{

			p = (person_interface*)malloc(sizeof(person_interface));
			fscanf(fpRead, "ID: %06d	�û���: %15s	���: %8d    ���˵ȼ�: %6d    ����ֵ: %4d    ��ǰ�������辭��: %6d	�����ȼ�: %3d	��ǰ����: %3d	������: %d\n", &p->ID, p->username, &p->money, &p->level, &p->empiricalvalue, &p->levelup, &p->pasturelevel, &p->currentNum, &p->allNum);
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


void printlist(person_interface *p1, char userName[])//��ӡ������Ϣ������̨ // edit by wt
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
			printf("\n\n\n                                                         ������Ϣ\n\n");
			printf("	              ***************************************************************************************\n");
			printf("	              *  ID: %06d                                                                         *\n	              %s\n",p->ID,kongge);
			printf("	              *  �û���: %-10s                                                                 *\n	              %s\n", p->username,kongge);
			printf("	              *  ���: %-10d                                                                   *\n	              %s\n", p->money,kongge);
			printf("	              *  ���˵ȼ�: %-d                                                                        *\n	              %s\n", p->level,kongge);
			printf("	              *  ����ֵ: %4d/%-5d                                                                 *\n	              %s\n", p->empiricalvalue, p->levelup,kongge);
			printf("	              *  �����ȼ�: %-2d                                                                       *\n	              %s\n",  p->pasturelevel,kongge);
			printf("	              *  ��ǰ����: %-2d/%-2d                                                                    *\n	              %s\n", p->currentNum, p->allNum,kongge);
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
		printf("�Ҳ����û���Ϣ��\n");
		_Countdown("ϵͳ����", 5, "s���˳�����");
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
		printf("Tips:������exit������һ���˵�^_^\n");
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
			printf("ָ�����\n");
			_Countdown("	(", 3, "���ת����ҳ�桭��)");
		}
	}
}