#pragma once
typedef  struct person// edit by wt
{
	int ID;//���
	char username[30];//�û���
	int money;//���
	int level;//���˵ȼ�
	int empiricalvalue;//����ֵ
	int levelup;//��ǰ�ȼ��������辭��
	int pasturelevel;//�����ȼ�
	int currentNum;//��ǰ����
	int allNum;//������
	struct person *next;//�����ν������ָ��
} person_interface;
int value_scorll(person_interface *p);									//������ // edit by wt
char* add_messgae_and_print(int ID, char userName[]);					//��ʽ��д���ļ� // edit by wt
person_interface *creatlist();											//�����洢�û���Ϣ������ // edit by wt
void printlist(person_interface *p1, char userName[]);					//��ӡ������Ϣ������̨ // edit by wt
void PersonInterface(char userName[]);									//���˽��� // edit by wt





