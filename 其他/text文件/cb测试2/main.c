
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using  namespace  std;

class  CData
{
public:
	CData() {};
	virtual  int  Compare(CData &) = 0;
	virtual  void Show() = 0;
	virtual  ~CData() {};
};

class  CNode
{
private:
	CData  *pData;
	CNode  *pNext;
public:
	CNode() { pData = 0; pNext = 0; };
	CNode(CNode  &node)
	{
		pData = node.pData;
		pNext = node.pNext;
	}
	void  InputData(CData  *pdata) { pData = pdata; }
	void  ShowNode() { pData->Show(); }
	CData  *GetData() { return  pData; }
	friend  class  CList;
};

class  CList
{
	CNode  *pHead;
public:
	CList() { pHead = 0; }
	~CList() { DeleteList(); }
	void  AddNode(CNode  *pnode);
	CNode  *DeleteNode(CNode  *);
	CNode *LookUp(CData  &);
	void  ShowList();
	void  DeleteList();
	CNode  *GetListHead() { return  pHead; }
	CNode  *GetListNextNode(CNode  *pnode);
};

CNode  *CList::GetListNextNode(CNode  *pnode)
{
	CNode  *p1 = pnode;
	return  p1->pNext;
};

void  CList::AddNode(CNode  *pnode)
{

	if (pHead == 0)
	{
		pHead = pnode;
		pnode->pNext = 0;
		return;
	}
	else
	{
		cout << pHead->pNext <<"hahaha"<< endl;
		pnode->pNext = pHead;
		cout << pnode->pNext->pNext << "hahaha" << endl;
		pHead = pnode;
	}
}

CNode *CList::DeleteNode(CNode  *pnode)
{
	CNode  *p1, *p2=NULL;
	p1 = pHead;
	while (p1 != pnode&&p1->pNext != 0)
	{
		p2 = p1;
		p1 = p1->pNext;
	}
	if (p1 == pHead)
	{
		pHead = pHead->pNext;
		return  pnode;
	}
	p2->pNext = p1->pNext;
	return  pnode;
}

CNode  *CList::LookUp(CData  &data)
{
	CNode  *p1 = pHead;
	while (p1)
	{
		if (p1->pData->Compare(data) == 0)
			return p1;
		p1 = p1->pNext;
	}
	return  0;
}

void  CList::ShowList()
{
	CNode  *p1 = pHead;
	while (p1)
	{
		cout << &p1<<endl;
		p1->pData->Show();
		p1 = p1->pNext;
	}
}

void  CList::DeleteList()
{
	CNode  *p1, *p2;
	p1 = pHead;
	while (p1)
	{
		delete  p1->pData;
		p2 = p1;
		p1 = p1->pNext;
		delete  p2;
	}
}

class  CTelRecord :public CData
{
private:
	char  szName[20];
	char  szNumber[20];
public:
	CTelRecord() { strcpy(szName, "\0");  strcpy(szNumber, "\0"); }
	CTelRecord(char *name, char *number)
	{
		strcpy(szName, name);
		strcpy(szNumber, number);
	}
	void  SetRecord(char  *name, char *number)
	{
		strcpy(szName, name);
		strcpy(szNumber, number);
	}
	int  Compare(CData &);
	void  Show();
};

int  CTelRecord::Compare(CData  &data)
{
	CTelRecord &temp = (CTelRecord &)data;
	return  strcmp(szName, temp.szName);
}

void  CTelRecord::Show()
{
	cout << setw(15) << szName << setw(15) << szNumber << endl;
}


void  DisplayRecord(CList &TelList)
{
	cout << setw(15) << "����" << setw(15) << "�绰����" << endl;
	TelList.ShowList();
	cout << endl << endl;
}

void  AddRecord(CList  &TelList)
{/********************/
 /*** ��Ӵ���********/
 /********************/

	char a[10], b[10];
	cout << "�����������ͺ���" << endl;
	cin >> a >> b;
	CTelRecord first(a, b);
	cout << "yes";
	CData *pdat;
	pdat = &first;
	cout << "yes";
	CNode f;
	f.InputData(pdat);
	TelList.AddNode(&f);
	cout << "��ӳɹ���" << endl;
	TelList.ShowList();


}

void  LookUpRecord(CList &TelList)
{
	/********************/
	/*** ��Ӵ���********/
	/********************/
	char a[10], b[10];
	cout << "�����������ͺ���:" << endl;
	cin >> a >> b;
	CTelRecord first(a, b);
	cout << "yes";
	TelList.LookUp(first)->ShowNode();
	cout << "yes";
}

void  DeleteRecord(CList &TelList)
{
	/********************/
	/*** ��Ӵ���********/
	/********************/
	int n;
	cout << "ɾ��������ѡ��1��ɾ�������б���ѡ��2";
	cin >> n;
	if (n == 1)
	{
		char a[10], b[10];
		cout << "�����������ͺ���:" << endl;
		cin >> a >> b;
		CTelRecord first(a, b);
		cout << "yes";
		CData *pdata;
		pdata = &first;
		cout << "yes";
		CNode del;
		del.InputData(pdata);
		TelList.DeleteNode(&del);
		cout << "ɾ���ɹ���" << endl;
	}
	if (n == 2)
	{
		TelList.DeleteList();
		cout << "ɾ���ɹ���" << endl;
	}

}


void  Operate(string  &strChoice, CList  &TelList)
{
	if (strChoice == "1")
		AddRecord(TelList);
	else  if (strChoice == "2")
		DisplayRecord(TelList);
	else  if (strChoice == "3")
		LookUpRecord(TelList);
	else  if (strChoice == "4")
		DeleteRecord(TelList);
	else
		cout << "��������������������ѡ��";
}


int  main(void)
{

	CList  TelList;
	 cout << "\t��ӭ����绰������ϵͳ\n";
	string  strChoice;
	//cin >> strChoice;
	do
	{
		cout << "\t1.��ӵ绰��\n";
		cout << "\t2.��ʾ�绰������\n";
		cout << "\t3.����������ѯ�绰������\n";
		cout << "\t4.��������ɾ���绰������\n";
		cout << "\t0.�˳�ϵͳ\n\n\n";
		cout << "����������ѡ��:";
		cin >> strChoice;
		Operate(strChoice, TelList);
		//getchar();
	} while (strChoice != "0");
	cout << "\n\n\t��ӭ�ٴ�ʹ�õ绰������ϵͳ\n\n";
	return 0;
}
