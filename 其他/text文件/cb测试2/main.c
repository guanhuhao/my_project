
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
	cout << setw(15) << "姓名" << setw(15) << "电话号码" << endl;
	TelList.ShowList();
	cout << endl << endl;
}

void  AddRecord(CList  &TelList)
{/********************/
 /*** 添加代码********/
 /********************/

	char a[10], b[10];
	cout << "请输入姓名和号码" << endl;
	cin >> a >> b;
	CTelRecord first(a, b);
	cout << "yes";
	CData *pdat;
	pdat = &first;
	cout << "yes";
	CNode f;
	f.InputData(pdat);
	TelList.AddNode(&f);
	cout << "添加成功！" << endl;
	TelList.ShowList();


}

void  LookUpRecord(CList &TelList)
{
	/********************/
	/*** 添加代码********/
	/********************/
	char a[10], b[10];
	cout << "请输入姓名和号码:" << endl;
	cin >> a >> b;
	CTelRecord first(a, b);
	cout << "yes";
	TelList.LookUp(first)->ShowNode();
	cout << "yes";
}

void  DeleteRecord(CList &TelList)
{
	/********************/
	/*** 添加代码********/
	/********************/
	int n;
	cout << "删除单个请选择1，删除整个列表请选择2";
	cin >> n;
	if (n == 1)
	{
		char a[10], b[10];
		cout << "请输入姓名和号码:" << endl;
		cin >> a >> b;
		CTelRecord first(a, b);
		cout << "yes";
		CData *pdata;
		pdata = &first;
		cout << "yes";
		CNode del;
		del.InputData(pdata);
		TelList.DeleteNode(&del);
		cout << "删除成功！" << endl;
	}
	if (n == 2)
	{
		TelList.DeleteList();
		cout << "删除成功！" << endl;
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
		cout << "输入错误，请重新输入你的选择：";
}


int  main(void)
{

	CList  TelList;
	 cout << "\t欢迎进入电话簿数据系统\n";
	string  strChoice;
	//cin >> strChoice;
	do
	{
		cout << "\t1.添加电话簿\n";
		cout << "\t2.显示电话簿内容\n";
		cout << "\t3.根据姓名查询电话簿数据\n";
		cout << "\t4.根据姓名删除电话簿数据\n";
		cout << "\t0.退出系统\n\n\n";
		cout << "请输入您的选择:";
		cin >> strChoice;
		Operate(strChoice, TelList);
		//getchar();
	} while (strChoice != "0");
	cout << "\n\n\t欢迎再次使用电话簿数据系统\n\n";
	return 0;
}
